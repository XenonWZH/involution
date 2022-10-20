#include <cstdio>
#include <iostream>
#include <vector>

const int MAXN = 3e5;
const int LOG_MAXN = 19;

struct Node {
#ifdef DBG
    int id;
#endif
    std::vector<struct Edge> adj;
    Node *f[LOG_MAXN + 1], *p;
    int d, cnt;
};

struct Edge {
    Node *s, *t;

    Edge(Node *s, Node *t) : s(s), t(t) {}
};

inline void addEdge(Node *u, Node *v) {
    u->adj.push_back(Edge(u, v));
    v->adj.push_back(Edge(v, u));
}

void prepare(Node *u, Node *f = nullptr) {
    u->f[0] = u->p = f;
    u->d = (f ? f->d : 0) + 1;
    for (int i = 1; i <= LOG_MAXN; i++) {
        if (u->f[i - 1]) {
            u->f[i] = u->f[i - 1]->f[i - 1];
        }
    }
    for (Edge &e : u->adj) {
        if (e.t == f) continue;
        prepare(e.t, u);
    }
}

inline Node *lca(Node *u, Node *v) {
    if (u->d < v->d) std::swap(u, v);
    if (u->d != v->d) {
        for (int i = LOG_MAXN; i >= 0; i--) {
            if (u->f[i] && u->f[i]->d >= v->d) {
                u = u->f[i];
            }
        }
    }
    if (u != v) {
        for (int i = LOG_MAXN; i >= 0; i--) {
            if (u->f[i] != v->f[i]) {
                u = u->f[i];
                v = v->f[i];
            }
        }
        return u->p;
    }
    return u;
}

long long dfs(Node *u, int m, Node *f = nullptr) {
    long long ans = 0;

    for (Edge &e : u->adj) {
        if (e.t == f) continue;
        ans += dfs(e.t, m, u);
        if (e.t->cnt == 0) ans += m;
        else if (e.t->cnt == 1) ans++;
    }

    if (u->p) u->p->cnt += u->cnt;

#ifdef DBG
    printf("[%d]: %lld %d\n", u->id, ans, u->cnt);
#endif

    return ans;
}

int main() {
    freopen("tree.in", "r", stdin);
    freopen("tree.out", "w", stdout);

    int n, m;
    scanf("%d %d", &n, &m);

    std::vector<Node> nodes(n + 1);

#ifdef DBG
    for (int i = 1; i <= n; i++) nodes[i].id = i;
#endif
    for (int i = 0; i < n - 1; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        addEdge(&nodes[u], &nodes[v]);
    }

    prepare(&nodes[1]);

    for (int i = 0; i < m; i++) {
        int a, b;
        scanf("%d %d", &a, &b);
        Node *u = &nodes[a], *v = &nodes[b];
        Node *f = lca(u, v);
        u->cnt++, v->cnt++, f->cnt -= 2;
    }

#ifdef DBG
    for (int i = 1; i <= n; i++) printf("%d ", nodes[i].cnt);
    putchar('\n');
#endif

    printf("%lld\n", dfs(&nodes[1], m));

    fclose(stdin);
    fclose(stdout);

    return 0;
}