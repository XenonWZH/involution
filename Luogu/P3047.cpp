#include <cstdio>
#include <vector>

const int MAXN = 1e5;
const int MAXK = 20;

struct Node {
    std::vector<struct Edge> e;
    int f[MAXK + 1];
} N[MAXN + 1];

struct Edge {
    Node *s, *t;

    Edge(Node *s, Node *t) : s(s), t(t) {}
};

int n, k;

inline void addEdge(int s, int t) {
    N[s].e.push_back(Edge(&N[s], &N[t]));
    N[t].e.push_back(Edge(&N[t], &N[s]));
}

void dp1(Node *v, Node *fa = nullptr) {
    for (Edge *e = &v->e.front(); e && e <= &v->e.back(); e++) {
        if (e->t == fa) continue;
        dp1(e->t, v);
        for (int i = 1; i <= k; i++) v->f[i] += e->t->f[i - 1];
    }
}

void dp2(Node *v, Node *fa = nullptr) {
    for (Edge *e = &v->e.front(); e && e <= &v->e.back(); e++) {
        if (e->t == fa) continue;
        for (int i = k; i >= 2; i--) e->t->f[i] -= e->t->f[i - 2];
        for (int i = 1; i <= k; i++) e->t->f[i] += v->f[i - 1];
        dp2(e->t, v);
    }
}

int main() {
    scanf("%d %d", &n, &k);

    for (int i = 1; i <= n - 1; i++) {
        int s, t;
        scanf("%d %d", &s, &t);
        addEdge(s, t);
    }
    for (int i = 1; i <= n; i++) scanf("%d", &N[i].f[0]);

    dp1(&N[1]);
    dp2(&N[1]);

    for (int i = 1; i <= n; i++) {
        int ans = 0;
        for (int j = 0; j <= k; j++) ans += N[i].f[j];
        printf("%d\n", ans);
    }

    return 0;
}