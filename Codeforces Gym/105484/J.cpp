#include <bits/stdc++.h>

namespace XenonWZH {
typedef long long ll;

void solve() {
    int n, m, k;
    scanf("%d %d %d", &n, &m, &k);

    std::vector<int> f(n + 1);
    std::map<int, bool> isf;
    for (int i = 1; i <= n; i++) {
        scanf("%d", &f[i]);
        isf[f[i]] = true;
    }

    std::map<std::pair<int, int>, int> g;
    std::vector<int> sum(k + 1, 0);
    int preAns = 0;
    for (int i = 1; i <= m; i++) {
        int x, y;
        scanf("%d %d", &x, &y);
        if (x != y) g[std::make_pair(std::min(x, y), std::max(x, y))]++;
        if (isf[x] && isf[y]) preAns++;
        if (isf[x] && !isf[y]) sum[y]++;
        if (isf[y] && !isf[x]) sum[x]++;
        if (x == y && !isf[x]) sum[x]++;
    }

    if (n >= k - 2) {
        printf("%d\n", m);
        return;
    }

    int ans = preAns;
    for (auto [pos, cnt] : g) {
        auto [x, y] = pos;
        if (!isf[x] && !isf[y]) {
            ans = std::max(ans, preAns + (x == y ? sum[x] : sum[x] + sum[y]) + g[std::make_pair(std::min(x, y), std::max(x, y))]);
        }
    }

    std::sort(sum.begin() + 1, sum.end());
    ans = std::max(ans, preAns + sum[k - 1] + sum[k]);

    printf("%d\n", ans);
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    int t;
    scanf("%d", &t);

    while (t--) solve();

    return 0;
}
};

int main() { return XenonWZH::main(); }