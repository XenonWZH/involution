#include <cstdio>
#include <algorithm>

const int MAXN = 1e4;
const int MAXM = 2e4;
const int MAXC = 3e4;

struct Edge {
    int a, b;
    int c1, c2;
    int id;

    bool operator<(const Edge &other) const {
        return c1 < other.c1;
    }
} E[MAXM + 1];

struct UFS {
    int f[MAXN + 1];

    void init(int n) {
        for (int i = 1; i <= n; i++) f[i] = i;
    }

    int find(int x) {
        return x == f[x] ? x : f[x] = find(f[x]);
    }

    void merge(int x, int y) {
        f[find(x)] = find(y);
    }
} ufs;

int n, k, m;
std::pair<int, int> id[MAXN];

inline bool solve(int limit) {
    static std::pair<int, int> ids[MAXN];
    ufs.init(n);
    int cnt = 0;

    for (int i = 1; i <= m - 1; i++) {
        Edge &e = E[i];
        if (e.c1 > limit) break;
        if (ufs.find(e.a) == ufs.find(e.b)) continue;

        ufs.merge(e.a, e.b);
        ids[++cnt] = std::make_pair(e.id, 1);
    }
    if (cnt < k) return false;

    for (int i = 1; i <= m - 1; i++) {
        if (cnt == n - 1) {
            for (int i = 1; i <= n - 1; i++) id[i] = ids[i];
            return true;
        }

        Edge &e = E[i];
        if (e.c2 > limit) continue;
        if (ufs.find(e.a) == ufs.find(e.b)) continue;

        ufs.merge(e.a, e.b);
        ids[++cnt] = std::make_pair(e.id, 2);
    }

    if (cnt == n - 1) {
        for (int i = 1; i <= n - 1; i++) id[i] = ids[i];
        return true;
    }

    return false;
}

int main() {
    scanf("%d %d %d", &n, &k, &m);

    int l = MAXC, r = 1;
    for (int i = 1; i <= m - 1; i++) {
        scanf("%d %d %d %d", &E[i].a, &E[i].b, &E[i].c1, &E[i].c2);
        E[i].id = i;
        l = std::min(l, std::min(E[i].c1, E[i].c2));
        r = std::max(r, std::max(E[i].c1, E[i].c2));
    }
    std::sort(E + 1, E + m);

    while (l < r) {
        int mid = (l + r) >> 1;

        if (solve(mid)) r = mid;
        else l = mid + 1;
    }

    printf("%d\n", l);
    std::sort(id + 1, id + n - 1);
    for (int i = 1; i <= n - 1; i++) {
        printf("%d %d\n", id[i].first, id[i].second);
    }

    return 0;
}