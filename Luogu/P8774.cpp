#include <bits/stdc++.h>

const int MOD = 998244353;
typedef long long ll;

ll pow(ll a, ll b) {
    ll ans = 1;
    for (; b; b >>= 1, a = a * a % MOD) if (b & 1) ans = ans * a % MOD;
    return ans;
}

ll inv(ll x) { return pow(x, MOD - 2); }

int main() {
    int n;
    scanf("%d", &n);

    std::vector<ll> x(n + 1), y(n + 1);
    for (int i = 1; i <= n; i++) scanf("%lld %lld", &x[i], &y[i]);

    std::vector<ll> t(n + 1);
    t[1] = (MOD - y[1] * inv(y[1] - x[1]) % MOD) % MOD;
    for (int i = 2; i <= n; i++) t[i] = ((t[i - 1] + MOD - 1) % MOD) * y[i] % MOD * inv(y[i] - x[i]) % MOD;

    printf("%lld\n", (MOD - t[n]) % MOD);

    return 0;
}