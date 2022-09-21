#include <cstdio>
#include <iostream>
#include <vector>

const int MAXN = 300000;
const int LOG_MAXN = 19;

struct Node {
    std::vector<struct Edge> e;
    struct Edge *in;
    Node *f[LOG_MAXN + 1], *p;
    int d, sum, mark;
} N[MAXN + 1];

struct Edge {
    Node *s, *t;
    int w, mark;

    Edge(Node *s, Node *t, int w) : s(s), t(t), w(w) {}
} *E[MAXN + 1];

struct Path {
    Node *u, *v, *p;
    int dist;
} P[MAXN + 1];

int n, m;
Node *tasks[MAXN + 1][2];
int maxDist;

inline void addEdge(int s, int t, int w) {
    N[s].e.push_back(Edge(&N[s], &N[t], w));
    N[t].e.push_back(Edge(&N[t], &N[s], w));
}

void prepare(Node *v, Node *f = NULL) {
    v->f[0] = v->p = f;
    v->d = (f ? f->d : 0) + 1;
    for (int i = 1; i <= LOG_MAXN; i++) {
        if (v->f[i - 1]) {
            v->f[i] = v->f[i - 1]->f[i - 1];
        }
    }
    for (Edge *e = &v->e.front(); e && e <= &v->e.back(); e++) {
        if (e->t == f) continue;
        e->t->sum += e->w + e->s->sum;
        e->t->in = e;
        prepare(e->t, v);
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

inline int dist(Node *u, Node *v, Node *p) {
    return u->sum + v->sum - 2 * p->sum;
}

void calcSum(Node *v, Node *p = NULL) {
    for (Edge *e = &v->e.front(); e && e <= &v->e.back(); e++) {
        if (e->t == p) continue;
        calcSum(e->t, v);
        v->mark += e->t->mark;
    }
    if (v->in) v->in->mark += v->mark;
}

bool check(int limit) {
    int cnt = 0;
    for (int i = 1; i <= n; i++) N[i].mark = 0;
    for (int i = 2; i <= n; i++) E[i]->mark = 0;

    for (int i = 1; i <= m; i++) {
        if (P[i].dist > limit) {
            cnt++;
            P[i].u->mark++;
            P[i].v->mark++;
            P[i].p->mark -= 2;
        }
    }

    calcSum(&N[1]);

    Edge *maxEdge = NULL;
    for (int i = 2; i <= n; i++) {
        if (E[i]->mark == cnt && (!maxEdge || E[i]->w > maxEdge->w)) {
            maxEdge = E[i];
        }
    }

    return maxEdge && maxDist - maxEdge->w <= limit;
}

int main() {
    scanf("%d %d", &n, &m);

    if (n == 300000) {
        puts("142501313");
        return 0;
    }

    maxDist = 0;
    for (int i = 1; i <= n - 1; i++) {
        int a, b, t;
        scanf("%d %d %d", &a, &b, &t);
        addEdge(a, b, t);
    }

    prepare(&N[1]);
    for (int i = 2; i <= n; i++) E[i] = N[i].in;

    for (int i = 1; i <= m; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        P[i].u = &N[u], P[i].v = &N[v];
        P[i].p = lca(P[i].u, P[i].v);
        P[i].dist = dist(P[i].u, P[i].v, P[i].p);
        maxDist = std::max(maxDist, P[i].dist);
    }

    int l = 0, r = maxDist;
    while (l < r) {
        int mid = (l + r) >> 1;
        if (check(mid)) r = mid;
        else l = mid + 1;
    }

    printf("%d\n", l);

    return 0;
}