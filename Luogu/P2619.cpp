#include <cstdio>
#include <algorithm>

const int MAXN = 5e4;
const int MAXM = 1e5;
const int INF = 100;

struct Edge {
    int s, t, c, col;

    bool operator<(const Edge &other) const {
        if (c == other.c) return col < other.col;
        return c < other.c;
    }
} E[MAXM];

struct UFS {
    int f[MAXN];

    void init(int n) {
        for (int i = 0; i < n; i++) f[i] = i;
    }

    int find(int x) {
        return x == f[x] ? x : f[x] = find(f[x]);
    }

    void merge(int x, int y) {
        f[find(x)] = find(y);
    }
} ufs;

int v, e, need;

inline std::pair<int, int> kruskal() {
    ufs.init(v);
    std::sort(E, E + e);

    int ans = 0, counts = 0, cntNeed = 0;

    for (int i = 0; i < e; i++) {
        Edge &edge = E[i];
        if (ufs.find(edge.s) == ufs.find(edge.t)) continue;
        ufs.merge(edge.s, edge.t);
        ans += edge.c;
        if (edge.col == 0) cntNeed++;
        if (++counts == v - 1) break;
    }

    return std::make_pair(cntNeed, ans);
}

int main() {
    scanf("%d %d %d", &v, &e, &need);
    for (int i = 0; i < e; i++) {
        scanf("%d %d %d %d", &E[i].s, &E[i].t, &E[i].c, &E[i].col);
    }

    int l = -INF, r = INF, ans = 0;
    while (l <= r) {
        int mid = (l + r) >> 1;

        for (int i = 0; i < e; i++) {
            if (E[i].col == 0) {
                E[i].c += mid;
            }
        }
        std::pair<int, int> res = kruskal();
        res.second -= mid * need;
        for (int i = 0; i < e; i++) {
            if (E[i].col == 0) {
                E[i].c -= mid;
            }
        }

        if (res.first >= need) l = mid + 1, ans = res.second;
        else r = mid - 1;
    }

    printf("%d\n", ans);

    return 0;
}