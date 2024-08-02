#include <bits/stdc++.h>

namespace XenonWZH {
typedef long long ll;

void solve() {
    int n;
    ll x;
    scanf("%d %lld", &n, &x);

    std::vector<ll> a(n + 1);
    for (int i = 1; i <= n; i++) scanf("%lld", &a[i]);

    std::vector<ll> s(n + 1);
    s[0] = 0;
    for (int i = 1; i <= n; i++) s[i] = s[i - 1] + a[i];

    std::vector<ll> f(n + 2);
    f[n] = (a[n] <= x);
    f[n + 1] = 0;
    for (int i = n - 1; i >= 1; i--) {
        auto t = std::upper_bound(s.begin(), s.end(), s[i - 1] + x);
        if (t == s.end()) f[i] += n - i + 1;
        else {
            f[i] += t - s.begin() - i;
            f[i] += f[t - s.begin() + 1];
        }
    }

    ll ans = 0;
    for (int i = 1; i <= n; i++) ans += f[i];

    printf("%lld\n", ans);
}

int main() {
    int t;

    scanf("%d", &t);

    while (t--) solve();

    return 0;
}
};

int main() {
    return XenonWZH::main();
}