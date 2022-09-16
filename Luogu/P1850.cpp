#include <cstdio>
#include <climits>
#include <cfloat>
#include <iostream>

const int MAXN = 2000;

int main() {
    int n, m, v, e;
    static int c[MAXN + 1];
    static int d[MAXN + 1];
    static double k[MAXN + 1];
    static long long g[MAXN + 1][MAXN + 1];

    scanf("%d %d %d %d", &n, &m, &v, &e);
    for (int i = 1; i <= n; i++) scanf("%d", &c[i]);
    for (int i = 1; i <= n; i++) scanf("%d", &d[i]);
    for (int i = 1; i <= n; i++) scanf("%lf", &k[i]);

    for (int i = 1; i <= v; i++) {
        for (int j = 1; j <= v; j++) {
            g[i][j] = INT_MAX;
        }
    }
    while (e--) {
        int a, b, w;
        scanf("%d %d %d", &a, &b, &w);
        g[a][b] = std::min(g[a][b], 1ll * w);
        g[b][a] = std::min(g[b][a], 1ll * w);
    }

    for (int k = 1; k <= v; k++) {
        for (int i = 1; i <= v; i++) {
            for (int j = 1; j <= v; j++) {
                g[i][j] = std::min(g[i][j], g[i][k] + g[k][j]);
            }
        }
    }
    for (int i = 1; i <= v; i++) g[i][i] = 0;

    static double f[MAXN + 1][MAXN + 1][2];
    f[1][0][0] = 0;
    f[1][0][1] = DBL_MAX;

    for (int i = 2; i <= n; i++) {
        f[i][0][0] = f[i - 1][0][0] + g[c[i - 1]][c[i]];
        f[i][0][1] = DBL_MAX;

        for (int j = 1; j <= m; j++) {
            f[i][j][0] = f[i][j][1] = DBL_MAX;

            if (f[i - 1][j][0] != DBL_MAX)  f[i][j][0] = std::min(f[i][j][0], f[i - 1][j][0] + g[c[i - 1]][c[i]]);
            if (f[i - 1][j][1] != DBL_MAX) f[i][j][0] = std::min(f[i][j][0], f[i - 1][j][1] + (g[d[i - 1]][c[i]] * k[i - 1]) + (g[c[i - 1]][c[i]] * (1 - k[i - 1])));
            if (f[i - 1][j - 1][0] != DBL_MAX)  f[i][j][1] = std::min(f[i][j][1], f[i - 1][j - 1][0] + (g[c[i - 1]][d[i]] * k[i]) + (g[c[i - 1]][c[i]] * (1 - k[i])));
            if (f[i - 1][j - 1][1] != DBL_MAX) f[i][j][1] = std::min(f[i][j][1], f[i - 1][j - 1][1] + (g[d[i - 1]][d[i]] * k[i - 1] * k[i]) + (g[c[i - 1]][d[i]] * (1 - k[i - 1]) * k[i]) + (g[d[i - 1]][c[i]] * k[i - 1] * (1 - k[i])) + (g[c[i - 1]][c[i]] * (1 - k[i - 1]) * (1 - k[i])));
        }
    }

    double ans = DBL_MAX;
    for (int i = 0; i <= m; i++) {
        ans = std::min(ans, f[n][i][0]);
        ans = std::min(ans, f[n][i][1]);
    }

    printf("%.2lf\n", ans);
    return 0;
}