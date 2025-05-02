#include <bits/stdc++.h>

namespace XenonWZH {
typedef long long ll;

void solve() {
    int n;
    scanf("%d", &n);

    ll ans = 0;
    for (int i = 1; i <= n; i++) ans += std::abs(i - (n + 1 - i));

    printf("%lld\n", ans / 2 + 1);
}

int main() {
    int t;
    scanf("%d", &t);

    while (t--) solve();

    return 0;
}
};

int main() { return XenonWZH::main(); }