#include <cstdio>
#include <algorithm>

const int MAXN = 200;
const int MAXK = 2e3;

int main() {
    int n, l, k;
    static double p[MAXN + 1];
    static int a[MAXN + 1];

    scanf("%d %d %d", &n, &l, &k);
    k += MAXN;

    for (int i = 1; i <= n; i++) {
        scanf("%lf", &p[i]);
        p[i] /= 100.0;
    }
    for (int i = 1; i <= n; i++) scanf("%d", &a[i]);

    static double f[MAXN + 1][MAXN + 1][2 * MAXN + 1];
    f[0][0][k] = 1;
    int left = k, right = k;

    for (int i = 1; i <= n; i++) {
        for (int j = 0; j < i; j++) {
            for (int m = left; m <= right; m++) {
                if (f[i - 1][j][m] != 0) {
                    f[i][j + 1][std::min(MAXN + n, m + a[i])] += f[i - 1][j][m] * p[i];
                    f[i][j][m] += f[i - 1][j][m] * (1.0 - p[i]);
                }
            }
        }

        if (a[i] == -1) left--;
        else right += a[i];
    }

    double ans = 0;
    for (int i = l; i <= n; i++) {
        for (int j = MAXN; j <= right; j++) {
            ans += f[n][i][j];
        }
    }

    printf("%.6f\n", ans);

    return 0;
}