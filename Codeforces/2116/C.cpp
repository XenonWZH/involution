#include <bits/stdc++.h>

namespace XenonWZH {
typedef long long ll;

const int MAXN = 5000;
const int MOD = 998244353;

int gcd(int a, int b) { return b == 0 ? a : gcd(b, a % b); }

void solve() {
    int n;
    scanf("%d", &n);

    std::vector<int> a(n + 1);
    for (int i = 1; i <= n; i++) scanf("%d", &a[i]);

    int g = a[1];
    for (int i = 2; i <= n; i++) g = gcd(g, a[i]);

    int cnt = 0;
    for (int i = 1; i <= n; i++) if (a[i] == g) cnt++;
    if (cnt) {
        printf("%d\n", n - cnt);
        return;
    }

    int ans = 1;
    g = INT_MAX;
    for (int i = 1; i <= n; i++) for (int j = 1; j <= n; j++) if (i != j) g = std::min(g, gcd(a[i], a[j]));
    while (true) {
        int gg = g;
        for (int i = 1; i <= n; i++) gg = std::min(gg, gcd(g, a[i]));
        if (gg == g) break;
        g = gg, ans++;
    }

    printf("%d\n", ans + n - 1);
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