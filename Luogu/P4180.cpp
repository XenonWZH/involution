#include <cstdio>
#include <climits>
#include <vector>
#include <algorithm>

const int MAXN = 1e5;
const int MAXM = 3e5;
const int LOG_MAXN = 17;

struct Node {
    std::vector<struct Edge> e;
    Node *p, *f[LOG_MAXN + 1];
    long long maxe[LOG_MAXN + 1][2];
    int d, id;
} N[MAXN + 1];

struct Edge {
    Node *s, *t;
    int sid, tid;
    long long w;
    bool v;

    Edge() {}
    Edge(Node *s, Node *t, long long w) : s(s), t(t), w(w) {}

    bool operator<(const Edge &other) const {
        return w < other.w;
    }
} E[MAXM + 1];

struct UnionFindSet {
    int fa[MAXN + 1];

    void init(int n) {
        for (int i = 1; i <= n; i++) fa[i] = i;
    }

    int find(int x) {
        return x == fa[x] ? x : fa[x] = find(fa[x]);
    }

    void merge(int x, int y) {
        fa[find(x)] = find(y); 
    }
} ufs;

int n, m;

inline void addEdge(int s, int t, long long w) {
    N[s].e.push_back(Edge(&N[s], &N[t], w));
    N[t].e.push_back(Edge(&N[t], &N[s], w));
}

inline long long kruskal() {
    ufs.init(n);
    std::sort(E + 1, E + m + 1);

    long long ans = 0;
    int counts = 0;

    for (int i = 1; i <= m; i++) {
        Edge &e = E[i];
        if (ufs.find(e.sid) == ufs.find(e.tid)) continue;
        e.v = true;
        addEdge(e.sid, e.tid, e.w);
        ufs.merge(e.sid, e.tid);
        ans += e.w;
        if (++counts == n - 1) break;
    }

    return ans;
}

void prepare(Node *v, Node *f = NULL) {
    v->f[0] = v->p = f;
    v->d = (f ? f->d : 0) + 1;
    v->maxe[0][1] = LLONG_MIN;
    for (int i = 1; i <= LOG_MAXN; i++) {
        if (v->f[i - 1]) {
            v->f[i] = v->f[i - 1]->f[i - 1];
            long long choice[4] = { v->maxe[i - 1][0], v->maxe[i - 1][1],
                                    v->f[i - 1]->maxe[i - 1][0], v->f[i - 1]->maxe[i - 1][1] };
            std::sort(choice, choice + 4);
            v->maxe[i][0] = choice[3];
            int p = 2;
            while (p >= 0 && choice[p] == choice[3]) p--;
            v->maxe[i][1] = (p == -1 ? LLONG_MIN : choice[p]);
        }
    }
    for (Edge *e = &v->e.front(); e && e <= &v->e.back(); e++) {
        if (e->t == f) continue;
        e->t->maxe[0][0] = e->w;
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

inline long long query(Node *v, Node *f, long long w) {
    long long res = LLONG_MIN;
    for (int i = LOG_MAXN; i >= 0; i--) {
        if (v->f[i] && v->f[i]->d >= f->d) {
            if (w != v->maxe[i][0]) res = std::max(res, v->maxe[i][0]);
            else res = std::max(res, v->maxe[i][1]);
            v = v->f[i];
        }
    }
    return res;
}

int main() {
    scanf("%d %d", &n, &m);
    for (int i = 1; i <= n; i++) N[i].id = i;
    for (int i = 1; i <= m; i++) {
        scanf("%d %d %lld", &E[i].sid, &E[i].tid, &E[i].w);
        E[i].s = &N[E[i].sid], E[i].t = &N[E[i].tid];
    }

    long long ans = LLONG_MAX;
    long long sum = kruskal();
    prepare(&N[1]);

    for (int i = 1; i <= m; i++) {
        if (!E[i].v) {
            Edge *e = &E[i];
            Node *f = lca(e->s, e->t);
            long long sw = query(e->s, f, e->w);
            long long tw = query(e->t, f, e->w);
            if (std::max(sw, tw) > LLONG_MIN) ans = std::min(ans, sum - std::max(sw, tw) + e->w);
        }
    }

    printf("%lld\n", ans);

    return 0;
}