#include <bits/stdc++.h>

namespace XenonWZH {
typedef long long ll;

const int MAXN = 5e5;
const int MOD = 998244353;

ll fac[MAXN + 1], inv[MAXN + 1], facInv[MAXN + 1], f[MAXN + 1];

int C(const int n, const int k) {
    if (k < 0 || k > n) return 0;
    if (k == 0) return 1;
    return fac[n] * facInv[k] % MOD * facInv[n - k] % MOD;
}

ll lucas(ll n, ll k) {
    if (!k) return 1;
    return C(n % MOD, k % MOD) * lucas(n / MOD, k / MOD) % MOD;
}

void prepare() {
    fac[0] = 1;
    for (int i = 1; i <= MAXN; i++) fac[i] = fac[i - 1] * i % MOD;

    inv[1] = 1;
    for (int i = 2; i <= MAXN; i++) inv[i] = ((-(MOD / i) * inv[MOD % i]) % MOD + MOD) % MOD;

    facInv[0] = 1;
    for (int i = 1; i <= MAXN; i++) facInv[i] = facInv[i - 1] * inv[i] % MOD;

    f[0] = 0, f[1] = 0, f[2] = 1;
    for (int i = 3; i <= MAXN; i++) {
        f[i] = (i - 1) * (f[i - 1] + f[i - 2]) % MOD;
    }
}

void solve() {
    ll a[27], sum, n;
    sum = n = 0;
    for (int i = 1; i <= 26; i++) {
        ll x;
        scanf("%lld", &x);
        if (x != 0) {
            sum += x;
            a[++n] = x;
        }
    }

    std::vector<ll> pre(n + 1, 0);
    for (int i = 1; i <= n; i++) pre[i] = pre[i - 1] + a[i];

    std::vector<std::vector<ll>> f(n + 1, std::vector<ll>(sum / 2 + 1, 0));
    f[0][sum / 2] = 1;
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j <= sum / 2; j++) {
            ll even = j, odd = (sum - sum / 2) - (pre[i - 1] - (sum / 2 - even));
            if (pre[i - 1] < sum / 2 - even) continue;
            if (a[i] <= even) f[i][even - a[i]] = (f[i][even - a[i]] + f[i - 1][even] * lucas(even, a[i]) % MOD) % MOD;
            if (a[i] <= odd) f[i][even] = (f[i][even] + f[i - 1][even] * lucas(odd, a[i]) % MOD) % MOD;
        }
    }

    printf("%lld\n", f[n][0]);
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    prepare();

    int t;
    scanf("%d", &t);

    while (t--) solve();

    return 0;
}
};

int main() { return XenonWZH::main(); }