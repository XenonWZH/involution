#include <cstdio>
#include <bitset>

const int MAXN = 1e5;
const int LOG_MAXA = 31;
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

int main() {
#ifndef DBG
    freopen("card.in", "r", stdin);
    freopen("card.out", "w", stdout);
#endif

    prepare();

    int n, k;
    static std::bitset<LOG_MAXA> a[MAXN + 1];

    scanf("%d %d", &n, &k);

    for (int i = 1; i <= n; i++) {
        int x;
        scanf("%d", &x);
        a[i] = x;
    }

    static long long bit[LOG_MAXA][2];

    for (int i = 0; i < LOG_MAXA; i++) {
        int cnt[2] = { 0, 0 };
        for (int j = 1; j <= n; j++) cnt[a[j][i]]++;
        bit[i][0] = bit[i][1] = 0;

        for (int j = 0; j <= k; j++) {
            bit[i][j % 2] = (bit[i][j % 2] + lucas(cnt[1], j) * lucas(cnt[0], k - j)) % MOD;
        }
    }

    static long long ans = 0;
    for (int i = 0; i < LOG_MAXA; i++) {
        ans = (ans + (1ll << i) * bit[i][1] % MOD) % MOD;
    }

    printf("%lld\n", ans);

#ifndef DBG
    fclose(stdin);
    fclose(stdout);
#endif

    return 0;
}