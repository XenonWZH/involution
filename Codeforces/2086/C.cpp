#include <bits/stdc++.h>

namespace XenonWZH {
typedef long long ll;

const int MAXN = 1e5;
const int MOD = 998244353;

void solve() {
    int n;
    scanf("%d", &n);

    std::vector<int> p(n + 1), d(n + 1);
    for (int i = 1; i <= n; i++) scanf("%d", &p[i]);
    for (int i = 1; i <= n; i++) scanf("%d", &d[i]);

    std::vector<bool> vis(n + 1);
    int ans = 0;
    for (int i = 1; i <= n; i++) {
        int t = d[i];
        while (!vis[t]) {
            ans++;
            vis[t] = true;
            t = p[t];
        }
        printf("%d ", ans);
    }

    puts("");
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