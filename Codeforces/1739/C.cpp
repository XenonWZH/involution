#include <cstdio>
#include <iostream>

const int MAXN = 60;
const int MOD = 998244353;

long long fac[MAXN + 1], inv[MAXN + 1], facInv[MAXN + 1], f[MAXN + 1];

inline int C(const int n, const int k) {
    if (k < 0 || k > n) return 0;
    if (k == 0) return 1;
    return fac[n] * facInv[k] % MOD * facInv[n - k] % MOD;
}

inline long long lucas(long long n, long long k) {
    if (!k) return 1;
    return C(n % MOD, k % MOD) * lucas(n / MOD, k / MOD) % MOD;
}

inline void prepare() {
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
    int n;

    scanf("%d", &n);

    long long ans1 = 0, ans2 = 0;
    bool flag = true;
    for (int i = n; i >= 1; i -= 2) {
        if (flag) {
            ans1 = (ans1 + lucas(i - 1, n / 2 - 1 - (n - i) / 2)) % MOD;
            ans2 = (ans2 + lucas(i - 2, n / 2 - (n - i) / 2)) % MOD;
        } else {
            ans2 = (ans2 + lucas(i - 1, n / 2 - 1 - (n - i) / 2)) % MOD;
            ans1 = (ans1 + lucas(i - 2, n / 2 - (n - i) / 2)) % MOD;
        }
        flag ^= true;
    }

    printf("%lld %lld 1\n", ans1, ans2);
}

int main() {
    prepare();

    int t;

    scanf("%d", &t);

    while (t--) solve();

    return 0;
}