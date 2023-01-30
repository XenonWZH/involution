#include <cstdio>
#include <cstring>
#include <algorithm>

const int MAXN = 50;
const int LOG_ANS = 64;

int main() {
    int n, m;
    scanf("%d %d", &n, &m);

    static bool f[LOG_ANS][MAXN + 1][MAXN + 1];
    static long long g[MAXN + 1][MAXN + 1];
    memset(g, 0x3f, sizeof(g));
    for (int i = 1; i <= m; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        f[0][u][v] = true, g[u][v] = 1;
    }

    for (int p = 1; p < LOG_ANS; p++) {
        for (int k = 1; k <= n; k++) {
            for (int i = 1; i <= n; i++) {
                for (int j = 1; j <= n; j++) {
                    if (f[p - 1][i][j] & f[p - 1][j][k]) {
                        f[p][i][k] = true, g[i][k] = 1;
                    }
                }
            }
        }
    }

    for (int k = 1; k <= n; k++) {
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                g[i][k] = std::min(g[i][k], g[i][j] + g[j][k]);
            }
        }
    }

    printf("%lld\n", g[1][n]);

    return 0;
}