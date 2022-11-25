#include <cstdio>
#include <vector>
#include <algorithm>

struct Edge {
    int u, v;
    int w;

    bool operator<(const Edge &o) const {
        return w < o.w;
    }
};

struct UnionFindSet {
    std::vector<int> a;

    void init(int n) {
        a.resize(n + 1);
        for (int i = 1; i <= n; i++) a[i] = i;
    }

    int find(int x) {
        return x == a[x] ? x : (a[x] = find(a[x]));
    }

    void merge(int x, int y) {
        a[find(x)] = find(y);
    }
};

int main() {
    int n, m;
    scanf("%d %d", &n, &m);

    std::vector<Edge> edges(m);
    for (int i = 0; i < m; i++) scanf("%d %d %d", &edges[i].u, &edges[i].v, &edges[i].w);

    auto kruskal = [&]() {
        UnionFindSet ufs;
        ufs.init(n);

        long long ans = 0;
        std::sort(edges.begin(), edges.end());
        for (int i = 0; i < m; i++) {
            if (ufs.find(edges[i].u) == ufs.find(edges[i].v)) continue;
            ans += edges[i].w;
            ufs.merge(edges[i].u, edges[i].v);
        }

        for (int i = 1; i <= n; i++) if (ufs.find(i) != ufs.find(1)) return -1ll;
        return ans;
    };

    long long ans = kruskal();
    if (ans == -1) puts("orz");
    else printf("%lld\n", ans);

    return 0;
}