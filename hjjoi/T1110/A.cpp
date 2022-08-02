#include <cstdio>

const int MAXN = 1e6;
const int MOD = 1e9 + 7;

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

int main() {
    prepare();

    int t;

    scanf("%d", &t);

    while (t--) {
        int n, m, k;

        scanf("%d %d %d", &n, &m, &k);
        printf("%lld\n", lucas(n - k * m - 1, m - 1) * n % MOD * inv[m] % MOD);
    }

    return 0;
}