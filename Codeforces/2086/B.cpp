#include <bits/stdc++.h>

namespace XenonWZH {
typedef long long ll;

const int MAXN = 1e5;
const int MOD = 998244353;

void solve() {
    ll n, k, x;
    scanf("%lld %lld %lld", &n, &k, &x);

    std::vector<ll> a(n);
    ll s = 0;
    for (int i = 0; i < n; i++) scanf("%lld", &a[i]), s += a[i];

    ll sum = s * k, ans = 0;
    while (sum - s >= x) {
        sum -= s;
        ans += n;
    }
    for (int i = 0; i < n; i++) {
        if (sum >= x) {
            sum -= a[i];
            ans++;
        } else break;
    }

    printf("%lld\n", ans);
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