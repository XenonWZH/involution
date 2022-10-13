#include <cstdio>

const int MAXN = 30;
const int MAXM = 100;
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
    for (int i = 3; i <= MAXN; i++) f[i] = (i - 1) * (f[i - 1] + f[i - 2]) % MOD;
}

inline long long pow(const int n, const int k) {
    long long ans = 1;
    for (long long num = n, t = k; t; num = num * num % MOD, t >>= 1) {
        if (t & 1) {
            ans = ans * num % MOD;
        }
    }
    return ans;
}

inline int popcnt(int x) {
    int res = 0;
    auto lowbit = [](int x) { return x & -x; };
    for (; x; x -= lowbit(x)) ++res;
    return res;
}

int main() {
    prepare();

    int n, m, k;
    static int v[MAXM + 1];

    scanf("%d %d %d", &n, &m, &k);
    for (int i = 0; i <= m; i++) scanf("%d", &v[i]);

    static long long f[MAXN + 1][MAXM + 2][MAXN + 1][MAXN + 1];
    f[0][0][0][0] = 1;

    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= m; j++) {
            for (int l = 0; l <= i / 2; l++) {
                for (int o = 0; o <= k; o++) {
                    if (f[i][j][l][o]) {
                        for (int num = 0; num <= n - i; ++num) {
                            f[i + num][j + 1][(l + num) / 2][o + (l + num) % 2] = (f[i + num][j + 1][(l + num) / 2][o + (l + num) % 2] + f[i][j][l][o] * pow(v[j], num) % MOD * C(i + num, num) % MOD) % MOD;
                        }
                    }
                }
            }
        }
    }

    long long ans = 0;
    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= k; j++) {
            if (popcnt(i) + j <= k) {
                ans = (ans + f[n][m + 1][i][j]) % MOD;
            }
        }
    }
    printf("%lld\n", ans);

    return 0;
}