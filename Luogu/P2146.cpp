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
    int val, tag;

    SegT(int l, int r, SegT *lc, SegT *rc) : l(l), r(r), lc(lc), rc(rc), val(0), tag(-1) {}

    void cover(const int delta) {
        if (delta == -1) return;
        val = delta == 1 ? r - l + 1 : 0;
        tag = delta == 1 ? 1 : 0;
    }

    void pushDown() {
        if (tag != -1) {
            lc->cover(tag);
            rc->cover(tag);
            tag = -1;
        }
    }

    void update(const int l, const int r, const int delta) {
        if (l > this->r || r < this->l) return;
        else if (l <= this->l && r >= this->r) cover(delta);
        else {
            pushDown();
            lc->update(l, r, delta);
            rc->update(l, r, delta);
            val = lc->val + rc->val;
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

inline void update(Node *u, Node *v, int w) {
    while (u->chain != v->chain) {
        if (u->chain->top->depth < v->chain->top->depth) std::swap(u, v);
        segment->update(u->chain->top->dfn, u->dfn, w);
        u = u->chain->top->fa;
    }

    if (u->depth > v->depth) std::swap(u, v);
    segment->update(u->dfn, v->dfn, w);
}

int main() {
    int n;
    scanf("%d", &n);

    std::vector<Node> nodes(n);
    for (int i = 1; i < n; i++) {
        int p;
        scanf("%d", &p);
        addEdge(&nodes[p], &nodes[i]);
    }

    split(&nodes[0]);
    segment = SegT::build(1, n);

    int q;
    scanf("%d", &q);
    while (q--) {
        char op[sizeof("uninstall")];
        int x;
        scanf("%s %d", op, &x);

        int bef = segment->val;

        if (op[0] == 'i') {
            update(&nodes[0], &nodes[x], 1);
            printf("%d\n", segment->val - bef);
        } else if (op[0] == 'u') {
            segment->update(nodes[x].dfn, nodes[x].dfn + nodes[x].size - 1, 0);
            printf("%d\n", bef - segment->val);
        }
    }

    return 0;
}