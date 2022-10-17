#include <cstdio>
#include <vector>

const int MAXN = 3e5;
const int LOG_MAXN = 19;

struct Node {
    std::vector<struct Edge> e;
    Node *f[LOG_MAXN + 1], *p;
    int d, ans;
} N[MAXN + 1];

struct Edge {
    Node *s, *t;

    Edge(Node *s, Node *t) : s(s), t(t) {}
};

inline void addEdge(int s, int t) {
    N[s].e.push_back(Edge(&N[s], &N[t]));
    N[t].e.push_back(Edge(&N[t], &N[s]));
}

void prepare(Node *v, Node *f = NULL) {
    v->f[0] = v->p = f;
    v->d = (f ? f->d : 0) + 1;
    for (int i = 1; i <= LOG_MAXN; i++) {
        if (v->f[i - 1]) {
            v->f[i] = v->f[i - 1]->f[i - 1];
        }
    }
    for (Edge &e : v->e) {
        if (e.t == f) continue;
        prepare(e.t, v);
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

void dfs(Node *v, Node *f = nullptr) {
    for (Edge &e : v->e) {
        if (e.t == f) continue;
        dfs(e.t, v);
    }
    if (v->p) v->p->ans += v->ans;
}

int main() {
    int n;
    static int a[MAXN];

    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
        a[i]--;
    }
    for (int i = 0; i < n - 1; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        addEdge(--u, --v);
    }

    prepare(&N[0]);

    for (int i = 0; i < n - 1; i++) {
        Node *u = &N[a[i]], *v = &N[a[i + 1]];
        Node *f = lca(u, v);
        u->ans++, v->ans++, f->ans--;
        if (f->p) f->p->ans--;
    }

    dfs(&N[0]);
    for (int i = 1; i < n; i++) N[a[i]].ans--;

    for (int i = 0; i < n; i++) printf("%d\n", N[i].ans);

    return 0;
}