#include <cstdio>
#include <iostream>
#include <vector>

const int MAXN = 2e5;

struct Node {
    std::vector<struct Edge> e;
    Node *p;
    int d;
} N[MAXN + 1];

struct Edge {
    Node *s, *t;

    Edge(Node *s, Node *t) : s(s), t(t) {}
};

int n, k;
int cnt;

inline void addEdge(int s, int t) {
    N[s].e.push_back(Edge(&N[s], &N[t]));
    N[t].e.push_back(Edge(&N[t], &N[s]));
    N[t].p = &N[s];
}

int dfs(Node *v, int limit, Node *f = NULL) {
    int mx = 0;
    for (Edge *e = &v->e.front(); e && e <= &v->e.back(); e++) {
        if (e->t == f) continue;
        mx = std::max(mx, dfs(e->t, limit, v));
    }
    if (v == &N[1] || v->p == &N[1]) return 0;
    if (mx + 1 < limit) return mx + 1;
    cnt++;
    return 0;
};

bool check(int limit) {
    cnt = 0;
    dfs(&N[1], limit);
    return cnt <= k;
};

void solve() {
    scanf("%d %d", &n, &k);

    for (int i = 1; i <= n; i++) {
        N[i].e.clear();
        N[i].d = 0;
        N[i].p = NULL;
    }
    N[1].d = 0;

    int maxd = 0;
    for (int i = 2; i <= n; i++) {
        int x;
        scanf("%d", &x);
        addEdge(x, i);
        N[i].d = N[x].d + 1;
        maxd = std::max(maxd, N[i].d);
    }

    int l = 1, r = n;
    while (l < r) {
        int mid = (l + r) / 2;
        if (check(mid)) r = mid;
        else l = mid + 1;
    }

    printf("%d\n", l);
}

int main() {
    int t;

    scanf("%d", &t);

    while (t--) solve();

    return 0;
}