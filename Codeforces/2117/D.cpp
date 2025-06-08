#include <bits/stdc++.h>

namespace XenonWZH {
typedef long long ll;

const int MAXN = 1e5;
const int MOD = 998244353;

int gcd(int a, int b) { return b == 0 ? a : gcd(b, a % b); }

void solve() {
    int n;
    scanf("%d", &n);

    std::vector<ll> a(n + 1);
    for (int i = 1; i <= n; i++) scanf("%lld", &a[i]);

    ll delta = a[2] - a[1];
    for (int i = 1; i < n; i++) {
        if (a[i + 1] - a[i] != delta) {
            puts("NO");
            return;
        }
    }

    if (delta > 0) for (int i = 1; i <= n; i++) a[i] -= delta * i;
    else for (int i = 1; i <= n; i++) a[i] += delta * (n - i + 1);

    if (a[1] < 0 || a[1] % (n + 1) != 0) {
        puts("NO");
        return;
    }

    for (int i = 2; i <= n; i++) {
        if (a[i] != a[i - 1]) {
            puts("NO");
            return;
        }
    }

    puts("YES");
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