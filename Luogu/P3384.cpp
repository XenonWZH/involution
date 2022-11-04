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
    for (Edge &e : v->e) {
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
    long long val, tag;

    SegT(int l, int r, SegT *lc, SegT *rc) : l(l), r(r), lc(lc), rc(rc), val(0), tag(0) {}

    void cover(const long long delta) {
        val += (r - l + 1) * delta;
        tag += delta;
    }

    void pushDown() {
        if (tag) {
            lc->cover(tag);
            rc->cover(tag);
            tag = 0;
        }
    }

    void update(const int l, const int r, const long long delta) {
        if (l > this->r || r < this->l) return;
        else if (l <= this->l && r >= this->r) cover(delta);
        else {
            pushDown();
            lc->update(l, r, delta);
            rc->update(l, r, delta);
            val = lc->val + rc->val;
        }
    }

    long long query(const int l, const int r) {
        if (l > this->r || r < this->l) return 0;
        else if (l <= this->l && r >= this->r) return val;
        else {
            pushDown();
            return lc->query(l, r) + rc->query(l, r);
        }
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

inline void update(Node *u, Node *v, long long w) {
    while (u->chain != v->chain) {
        if (u->chain->top->depth < v->chain->top->depth) std::swap(u, v);
        segment->update(u->chain->top->dfn, u->dfn, w);
        u = u->chain->top->fa;
    }

    if (u->depth > v->depth) std::swap(u, v);
    segment->update(u->dfn, v->dfn, w);
}

inline long long query(Node *u, Node *v) {
    long long res = 0;
    while (u->chain != v->chain) {
        if (u->chain->top->depth < v->chain->top->depth) std::swap(u, v);
        res += segment->query(u->chain->top->dfn, u->dfn);
        u = u->chain->top->fa;
    }

    if (u->depth > v->depth) std::swap(u, v);
    res += segment->query(u->dfn, v->dfn);

    return res;
}

int main() {
    int n, m, r, p;
    scanf("%d %d %d %d", &n, &m, &r, &p);

    std::vector<Node> nodes(n + 1);
    std::vector<long long> val(n + 1);
    for (int i = 1; i <= n; i++) scanf("%lld", &val[i]);
    for (int i = 1; i <= n - 1; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        addEdge(&nodes[u], &nodes[v]);
    }

    split(&nodes[r]);

    segment = SegT::build(1, n);
    for (int i = 1; i <= n; i++) segment->update(nodes[i].dfn, nodes[i].dfn, val[i]);

    while (m--) {
        int op;
        scanf("%d", &op);

        if (op == 1) {
            int u, v;
            long long w;
            scanf("%d %d %lld", &u, &v, &w);
            update(&nodes[u], &nodes[v], w);
        } else if (op == 2) {
            int u, v;
            scanf("%d %d", &u, &v);
            printf("%lld\n", query(&nodes[u], &nodes[v]) % p);
        } else if (op == 3) {
            int v;
            long long w;
            scanf("%d %lld", &v, &w);
            segment->update(nodes[v].dfn, nodes[v].dfn + nodes[v].size - 1, w);
        } else if (op == 4) {
            int v;
            scanf("%d", &v);
            printf("%lld\n", segment->query(nodes[v].dfn, nodes[v].dfn + nodes[v].size - 1) % p);
        }
    }

    return 0;
}