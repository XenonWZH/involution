#include <cstdio>
#include <cstring>

const int MAXN = 100;
const int MAXM = 2000;
const int MOD = 998244353;

int main() {
    int n, m;
    static long long a[MAXN + 1][MAXM + 1];

    scanf("%d %d", &n, &m);
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            scanf("%lld", &a[i][j]);
        }
    }

    static long long s[MAXN + 1];
    for (int i = 1; i <= n; i++) {
        s[i] = 0;
        for (int j = 1; j <= m; j++) s[i] = (s[i] + a[i][j]) % MOD;
    }

    long long ans = 0;
    static long long f[MAXN + 1][2 * MAXN + 2];
    for (int e = 1; e <= m; e++) {
        memset(f, 0, sizeof(f));
        f[0][n] = 1;
        for (int i = 1; i <= n; i++) {
            for (int j = n - i; j <= n + i; j++) {
                f[i][j] = (f[i - 1][j] + f[i - 1][j - 1] * a[i][e] % MOD + f[i - 1][j + 1] * ((s[i] - a[i][e] + MOD) % MOD) % MOD) % MOD;
            }
        }
        for (int i = 1; i <= n; i++) ans = (ans + f[n][n + i]) % MOD;
    }

    static int g[MAXN + 1][MAXN + 1];
    g[0][0] = 1;
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j <= n; j++) {
            g[i][j] = (g[i - 1][j] + (j > 0 ? g[i - 1][j - 1] * s[i] % MOD : 0)) % MOD;
        }
    }
    for (int i = 1; i <= n; i++) ans = (ans + MOD - g[n][i]) % MOD;

    printf("%lld\n", ans * (MOD - 1) % MOD);

    return 0;
}