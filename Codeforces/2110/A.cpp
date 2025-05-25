#include <bits/stdc++.h>

namespace XenonWZH {
typedef long long ll;

const int MAXN = 1e5;
const int MOD = 998244353;

void solve() {
    int n;
    scanf("%d", &n);

    std::vector<int> a(n + 1);
    for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
    std::sort(a.begin() + 1, a.end());
    for (int i = 1; i <= n; i++) a[i] %= 2;

    int ans = INT_MAX;
    for (int i = 1; i <= n; i++) {
        int j = n;
        while (a[j] != a[i]) j--;
        ans = std::min(ans, (i - 1) + (n - j));
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