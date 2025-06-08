#include <bits/stdc++.h>

namespace XenonWZH {
typedef long long ll;

const int MAXN = 1e5;
const int MOD = 998244353;

void solve() {
    int n;
    scanf("%d", &n);

    std::vector<int> a(n + 1), b(n + 1);
    for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
    for (int i = 1; i <= n; i++) scanf("%d", &b[i]);

    std::vector<int> c(a), d(b);
    for (int i = 1; i <= n; i++) if (i % 2 == 0) std::swap(c[i], d[i]);

    std::vector<std::vector<int>> pc(n + 1), pd(n + 1);
    for (int i = 1; i <= n; i++) pc[c[i]].push_back(i), pd[d[i]].push_back(i);

    int ans = 0;
    for (int i = 1; i <= n; i++) if (!pc[i].empty() && !pd[i].empty()) ans = std::max(ans, std::min(pc[i].back(), pd[i].back()));
    for (int i = 1; i <= n; i++) {
        if (pc[i].size() >= 2) {
            auto p = pc[i].end();
            int x = *(--p), y = *(--p);
            if (y == x - 1) {
                if (pc[i].size() >= 3) {
                    int z = *(--p);
                    ans = std::max(ans, z);
                }
            } else ans = std::max(ans, y);
        }
        if (pd[i].size() >= 2) {
            auto p = pd[i].end();
            int x = *(--p), y = *(--p);
            if (y == x - 1) {
                if (pd[i].size() >= 3) {
                    int z = *(--p);
                    ans = std::max(ans, z);
                }
            } else ans = std::max(ans, y);
        }
    }

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