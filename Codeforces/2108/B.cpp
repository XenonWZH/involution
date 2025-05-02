#include <bits/stdc++.h>

namespace XenonWZH {
typedef long long ll;

ll lowbit(ll x) {
    return x & (-x);
}

void solve() {
    ll n, x;
    scanf("%lld %lld", &n, &x);

    std::vector<ll> b;
    ll t = x;
    while (t) {
        b.push_back(lowbit(t));
        t -= lowbit(t);
    }

    if (b.size() >= n) {
        printf("%lld\n", x);
        return;
    }
    int m = b.size();

    if (x == 0) {
        if (n == 1) puts("-1");
        else {
            ll ans = 0;
            if (n % 2 == 1) ans += 6, n -= 3;
            ans += n;
            printf("%lld\n", ans);
        }
    } else if (x == 1) {
        if (n % 2 == 1) printf("%lld\n", n);
        else printf("%lld\n", 5 + (n - 2));
    } else printf("%lld\n", x + (n - m) + (n - m) % 2);
}

int main() {
    int t;
    scanf("%d", &t);

    while (t--) solve();

    return 0;
}
};

int main() { return XenonWZH::main(); }