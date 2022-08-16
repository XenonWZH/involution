#include <cstdio>
#include <algorithm>

const int MAXN = 50;

int main() {
#ifndef DBG
    freopen("max.in", "r", stdin);
    freopen("max.out", "w", stdout);
#endif

    int n, p;
    static int a[MAXN + 5];

    scanf("%d", &n);

    int sum = 0;
    static double fac[MAXN + 5];
    fac[0] = 1;

    for (int i = 1; i <= n; i++) {
        scanf("%d", &a[i]);
        sum += a[i];
        fac[i] = fac[i - 1] * i;
    }
    scanf("%d", &p);

    if (sum <= p) {
        printf("%lf\n", (double)n);
        return 0;
    }

    static long long dp[MAXN + 5][MAXN + 5];
    dp[0][0] = 1;

    for (int i = 1; i <= n; i++) {
        for (int j = i; j >= 1; j--) {
            for (int k = p; k >= a[i]; k--) {
                dp[j][k] += dp[j - 1][k - a[i]];
            }
        }
    }

    double ans = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j <= p; j++) {
            ans += dp[i][j] * fac[i] * fac[n - i];
        }
    }

    printf("%lf\n", ans / fac[n]);

#ifndef DBG
    fclose(stdin);
    fclose(stdout);
#endif

    return 0;
}
