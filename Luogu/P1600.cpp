#include <cstdio>
#include <vector>
#include <algorithm>
#include <stack>

const int MAXN = 3e5;

struct Tag {
    int x;
    bool remove;

    Tag(int x, bool remove) : x(x), remove(remove) {}
};

struct Node {
    std::vector<struct Edge> e;
    Node *fa, *ch;
    int depth, size, w, index, ans;
    bool visited;
    struct Chain *chain;
    std::vector<Tag> tagsForward, tagsBackward;
} N[MAXN + 1];

struct Edge {
    Node *s, *t;

    Edge(Node *s, Node *t) : s(s), t(t) {}
};

struct Chain {
    Node *top, *bottom;
    std::vector<Node *> nodes;
    int len;
} chains[MAXN + 1];

inline void addEdge(int s, int t) {
    N[s].e.push_back(Edge(&N[s], &N[t]));
    N[t].e.push_back(Edge(&N[t], &N[s]));
}

int n, chainCnt;

void dfs1(Node *v, Node *fa = NULL) {
    v->size = 1;

    for (Edge *e = &v->e.front(); e && e <= &v->e.back(); e++) {
        if (e->t == fa) continue;
        e->t->fa = v;
        e->t->depth = v->depth + 1;
        dfs1(e->t, v);
        v->size += e->t->size;
        if (!v->ch || v->ch->size < e->t->size) v->ch = e->t;
    }
}

void dfs2(Node *v) {
    if (!v->fa || v != v->fa->ch) {
        v->chain = &chains[++chainCnt];
        v->chain->top = v;
        v->index = 0;
    } else {
        v->chain = v->fa->chain;
        v->index = v->fa->index + 1;
    }
    v->chain->nodes.push_back(v);
    v->chain->bottom = v;

    if (v->ch) dfs2(v->ch);
    for (Edge *e = &v->e.front(); e && e <= &v->e.back(); e++) {
        if (e->t->fa == v && e->t != v->ch) {
            dfs2(e->t);
        }
    }
}

inline void split() {
    N[1].depth = 1;

    dfs1(&N[1]);
    dfs2(&N[1]);

    for (int i = 1; i <= chainCnt; i++) chains[i].len = chains[i].nodes.size();
}

inline Node *lca(Node *u, Node *v) {
    while (u->chain != v->chain) {
        if (u->chain->top->depth < v->chain->top->depth) std::swap(u, v);
        u = u->chain->top->fa;
    }
    if (u->depth > v->depth) return v;
    else return u;
}

inline int dist(Node *u, Node *v, Node *p) {
    return u->depth + v->depth - p->depth * 2;
}

inline void addTag(bool forward, Chain *chain, int s, int t, int x) {
    if (forward) {
        if (s > t) return;
        chain->nodes[s]->tagsForward.push_back(Tag(x, false));
        chain->nodes[t]->tagsForward.push_back(Tag(x, true));
    } else {
        if (t > s) return;
        chain->nodes[s]->tagsBackward.push_back(Tag(x, false));
        chain->nodes[t]->tagsBackward.push_back(Tag(x, true));
    }
}

inline void play(Node *s, Node *t) {
    if (s == t) {
        if (s->w == 0) s->ans++;
        return;
    }

    Node *p = lca(s, t), *u = s, *v = t;
    if (dist(s, p, p) == p->w) p->ans++;

    if (p != s) {
        while (u->chain != p->chain) {
            addTag(false, u->chain, u->index, 0, s->depth - u->chain->bottom->depth);
            u = u->chain->top->fa;
        }
        addTag(false, u->chain, u->index, p->index + 1, s->depth - u->chain->bottom->depth);
    }

    if (p != t) {
        while (v->chain != p->chain) {
            addTag(true, v->chain, 0, v->index, (s->depth - p->depth) + (v->chain->top->depth - p->depth));
            v = v->chain->top->fa;
        }
        addTag(true, v->chain, p->index + 1, v->index, (s->depth - p->depth) + (v->chain->top->depth - p->depth));
    }
}

inline void solve() {
    for (int i = 1; i <= chainCnt; i++) {
        Chain &chain = chains[i];

        static int _cnt[MAXN * 2 + 1], *cnt = _cnt + MAXN;

        for (int j = 0; j < chain.len; j++) {
            for (std::vector<Tag>::const_iterator it = chain.nodes[j]->tagsForward.begin(); it != chain.nodes[j]->tagsForward.end(); it++) {
                if (!it->remove) cnt[it->x]++;
            }

            chain.nodes[j]->ans += cnt[chain.nodes[j]->w - j];

            for (std::vector<Tag>::const_iterator it = chain.nodes[j]->tagsForward.begin(); it != chain.nodes[j]->tagsForward.end(); it++) {
                if (it->remove) cnt[it->x]--;
            }
        }

        for (int j = chain.len - 1; j >= 0; j--) {
            for (std::vector<Tag>::const_iterator it = chain.nodes[j]->tagsBackward.begin(); it != chain.nodes[j]->tagsBackward.end(); it++) {
                if (!it->remove) cnt[it->x]++;
            }

            chain.nodes[j]->ans += cnt[chain.nodes[j]->w - chain.len + j + 1];

            for (std::vector<Tag>::const_iterator it = chain.nodes[j]->tagsBackward.begin(); it != chain.nodes[j]->tagsBackward.end(); it++) {
                if (it->remove) cnt[it->x]--;
            }
        }
    }
}

int main() {
    int m;
    scanf("%d %d", &n, &m);
    for (int i = 1; i <= n - 1; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        addEdge(u, v);
    }

    for (int i = 1; i <= n; i++) {
        scanf("%d", &N[i].w);
    }

    split();

    while (m--) {
        int s, t;
        scanf("%d %d", &s, &t);
        play(&N[s], &N[t]);
    }

    solve();

    for (int i = 1; i <= n; i++) printf("%d%c", N[i].ans, i == n ? '\n' : ' ');

    return 0;
}