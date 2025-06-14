#include <bits/stdc++.h>

namespace XenonWZH {
typedef long long ll;

const int MAXN = 1e5;
const int MOD = 998244353;
const int LOG = 31;
const int LOGG = 61;

ll gcd(ll a, ll b) { return b == 0 ? a : gcd(b, a % b); }

ll pow(ll a, ll b) {
    ll ans = 1 % MOD;
    for (; b; b >>= 1, a = a * a % MOD) if (b & 1) ans = ans * a % MOD;
    return ans;
}

ll lowbit(ll x) { return x & (-x); }

void solve() {
    int n;
    ll k;
    scanf("%d %lld", &n, &k);

    std::vector<ll> a(n + 1);
    for (int i = 1; i <= n; i++) scanf("%lld", &a[i]);

    ll ans = 0;
    for (int i = 1; i <= n; i++) {
        ll x = a[i];
        while (x != 0) x -= lowbit(x), ans++;
    }

    std::vector<ll> cost;
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j <= LOG; j++) {
            if (((a[i] >> j) & 1) == 0) {
                cost.push_back(1ll << j);
            }
        }
    }

    std::sort(cost.begin(), cost.end());
    for (auto x : cost) {
        if (x > k) break;
        k -= x, ans++;
    }

    for (int i = LOG + 1; i <= LOGG; i++) {
        if ((1ll << i) * n >= k) {
            ans += k / (1ll << i);
            break;
        } else k -= (1ll << i) * n, ans += n;
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