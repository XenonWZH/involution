#include <cstdio>
#include <vector>
#include <queue>
#include <unordered_map>

struct UnionFindSet {
    std::vector<int> a;
    std::vector<std::unordered_map<int, int>> e;
    std::queue<std::pair<int, int>> q;

    void init(int n) {
        a.resize(n + 1);
        e.resize(n + 1);
        for (int i = 1; i <= n; i++) a[i] = i;
        for (int i = 1; i <= n; i++) e[i].clear();
        while (!q.empty()) q.pop();
    }

    int find(int x) {
        return x == a[x] ? x : (a[x] = find(a[x]));
    }

    void merge(int x, int y) {
        x = find(x), y = find(y);
        if (x == y) return;
        for (auto it : e[x]) {
            if (e[y][it.first]) q.emplace(e[y][it.first], it.second);
            else e[y][it.first] = it.second;
        }
        a[x] = y;
        e[x].clear();
    }

    void solve() {
        while (!q.empty()) {
            merge(q.front().first, q.front().second);
            q.pop();
        }
    }
} ufs;

int main() {
    int n, m, k;
    scanf("%d %d %d", &n, &m, &k);

    ufs.init(n);

    for (int i = 1; i <= m; i++) {
        int u, v, w;
        scanf("%d %d %d", &u, &v, &w);
        if (ufs.e[v][w]) ufs.q.emplace(ufs.e[v][w], u);
        else ufs.e[v][w] = u;
    }

    ufs.solve();

    std::vector<long long> cnt(n + 1, 0);
    for (int i = 1; i <= n; i++) cnt[ufs.find(i)]++;

    long long ans = 0;
    for (int i = 1; i <= n; i++) ans += cnt[i] * (cnt[i] - 1) / 2;

    printf("%lld\n", ans);

    return 0;
}