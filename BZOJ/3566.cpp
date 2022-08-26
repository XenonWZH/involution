#include <cstdio>

const int MAXN = 500000;

struct Node {
    struct Edge *e;
    double q;
    double f;
    bool v;
} N[MAXN + 1];

struct Edge {
    Node *s, *t;
    double p;
    Edge *n;

    Edge(Node *s, Node *t, double p) : s(s), t(t), p(p), n(s->e) {}
};

inline void addEdge(int s, int t, double p) {
    N[s].e = new Edge(&N[s], &N[t], p);
    N[t].e = new Edge(&N[t], &N[s], p);
}

void dfs(Node *u) {
    u->v = true;

    for (Edge *e = u->e; e; e = e->n) {
        if (!e->t->v) {
            dfs(e->t);
            u->f = u->f + e->t->f * e->p - u->f * e->t->f * e->p;
        }
    }
}

void dp(Node *u) {
    u->v = true;

    for (Edge *e = u->e; e; e = e->n) {
        if (!e->t->v) {
            double p;
            if (1 - e->p * e->t->f) p = (u->f - e->p * e->t->f) / (1 - e->p * e->t->f);
            else p = 1;
            p *= e->p;
            e->t->f += p * (1 - e->t->f);
            dp(e->t);
        }
    }
}

int main() {
    int n;

    scanf("%d", &n);
    for (int i = 0; i < n - 1; i++) {
        int a, b, p;
        scanf("%d %d %d", &a, &b, &p);
        addEdge(a, b, p / 100.0);
    }
    for (int i = 1; i <= n; i++) {
        scanf("%lf", &N[i].q);
        N[i].q = N[i].f = N[i].q / 100;
    }

    for (int i = 1; i <= n; i++) N[i].v = false;
    dfs(&N[1]);
    for (int i = 1; i <= n; i++) N[i].v = false;
    dp(&N[1]);

    double ans = 0;
    for (int i = 1; i <= n; i++) ans += N[i].f;

    printf("%.6f\n", ans);

    return 0;
}
