#include <cstdio>
#include <iostream>
#include <vector>
#include <set>

const int MAXN = 5e4;

struct Node {
    std::vector<struct Edge> e;
    std::multiset<int> s;
} N[MAXN + 1];

struct Edge {
    Node *s, *t;
    int w;

    Edge(Node *s, Node *t, int w) : s(s), t(t), w(w) {}
};

int n, m;
int cnt = 0;

inline void addEdge(int s, int t, int w) {
    N[s].e.push_back(Edge(&N[s], &N[t], w));
    N[t].e.push_back(Edge(&N[t], &N[s], w));
}

int dfs(Node *v, int limit, Node *f = NULL) {
    v->s.clear();
    for (Edge *e = &v->e.front(); e && e <= &v->e.back(); e++) {
        if (e->t == f) continue;
        int res = dfs(e->t, limit, v);
        if (res + e->w >= limit) cnt++;
        else v->s.insert(res + e->w);
    }

    int max = 0;
    while (!v->s.empty()) {
        if (v->s.size() == 1) return std::max(max, *v->s.begin());
        std::multiset<int>::iterator it = v->s.lower_bound(limit - *v->s.begin());
        if (it == v->s.begin() && v->s.count(*it) == 1) it++;
        if (it == v->s.end()) {
            max = std::max(max, *v->s.begin());
            v->s.erase(v->s.begin());
        } else {
            cnt++;
            v->s.erase(it);
            v->s.erase(v->s.begin());
        }
    }

    return max;
}

int main() {
    scanf("%d %d", &n, &m);

    int max = 0;
    for (int i = 1; i <= n - 1; i++) {
        int a, b, l;
        scanf("%d %d %d", &a, &b, &l);
        addEdge(a, b, l);
        max += l;
    }

    int l = 0, r = max;
    while (l < r) {
        int mid = (l + r + 1) / 2;
        cnt = 0;
        dfs(&N[1], mid);
        if (cnt >= m) l = mid;
        else r = mid - 1;
    }

    printf("%d\n", l);

    return 0;
}