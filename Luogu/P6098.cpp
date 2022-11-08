#include <cstdio>
#include <vector>

struct Node {
    std::vector<struct Edge> e;
    struct Chain *chain;
    int size, dfn, depth;
    Node *fa, *ch;
};

struct Edge {
    Node *s, *t;

    Edge(Node *s, Node *t) : s(s), t(t) {}
};

struct Chain {
    Node *top;

    Chain(Node *top) : top(top) {}
};

inline void addEdge(Node *u, Node *v) {
    u->e.push_back(Edge(u, v));
    v->e.push_back(Edge(v, u));
}

void dfs1(Node *v, Node *fa = nullptr) {
    v->size = 1;

    for (Edge &e : v->e) {
        if (e.t == fa) continue;
        e.t->fa = v;
        e.t->depth = v->depth + 1;
        dfs1(e.t, v);
        v->size += e.t->size;
        if (!v->ch || v->ch->size < e.t->size) v->ch = e.t;
    }
}

void dfs2(Node *v) {
    static int ts = 0;
    v->dfn = ++ts;

    if (!v->fa || v != v->fa->ch) v->chain = new Chain(v);
    else v->chain = v->fa->chain;

    if (v->ch) dfs2(v->ch);
    for (Edge e : v->e) {
        if (e.t->fa == v && e.t != v->ch) {
            dfs2(e.t);
        }
    }
}

inline void split(Node *v) {
    v->depth = 1;
    dfs1(v);
    dfs2(v);
}

struct SegT {
    int l, r;
    SegT *lc, *rc;
    int val;

    SegT(int l, int r, SegT *lc, SegT *rc) : l(l), r(r), lc(lc), rc(rc) {}

    void update(const int pos, const int delta) {
        if (pos < this->l || pos > this->r) return;
        else if (pos == this->l && pos == this->r) val = delta;
        else {
            lc->update(pos, delta);
            rc->update(pos, delta);
            val = lc->val ^ rc->val;
        }
    }

    int query(const int l, const int r) {
        if (l > this->r || r < this->l) return 0;
        else if (l <= this->l && r >= this->r) return val;
        else return lc->query(l, r) ^ rc->query(l, r);
    }

    static SegT *build(const int l, const int r) {
        if (l > r) return nullptr;
        else if (l == r) return new SegT(l, r, nullptr, nullptr);
        else {
            const int mid = l + (r - l) / 2;
            return new SegT(l, r, build(l, mid), build(mid + 1, r));
        }
    }
} *segment;

inline int query(Node *u, Node *v) {
    int res = 0;
    while (u->chain != v->chain) {
        if (u->chain->top->depth < v->chain->top->depth) std::swap(u, v);
        res ^= segment->query(u->chain->top->dfn, u->dfn);
        u = u->chain->top->fa;
    }

    if (u->depth > v->depth) std::swap(u, v);
    res ^= segment->query(u->dfn, v->dfn);

    return res;
}

int main() {
    int n, q;
    scanf("%d %d", &n, &q);

    std::vector<Node> nodes(n + 1);
    std::vector<int> e(n + 1);
    for (int i = 1; i <= n; i++) scanf("%d", &e[i]);
    for (int i = 1; i <= n - 1; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        addEdge(&nodes[u], &nodes[v]);
    }

    split(&nodes[1]);

    segment = SegT::build(1, n);
    for (int i = 1; i <= n; i++) segment->update(nodes[i].dfn, e[i]);

    while (q--) {
        int op;
        scanf("%d", &op);

        if (op == 1) {
            int i, v;
            scanf("%d %d", &i, &v);
            segment->update(nodes[i].dfn, v);
        } else if (op == 2) {
            int i, j;
            scanf("%d %d", &i, &j);
            printf("%d\n", query(&nodes[i], &nodes[j]));
        }
    }

    return 0;
}