#include <cstdio>
#include <cstring>
#include <algorithm>

const int MAXN = 100;
const int INF = 0x3f3f3f3f;

int main() {
    int n, m;
    scanf("%d %d", &n, &m);

    static int f[MAXN + 1][MAXN + 1], g[MAXN + 1][MAXN + 1];
    memset(f, 0x3f ,sizeof(f));
    for (int i = 1; i <= n; i++) f[i][i] = 0;
    for (int i = 1; i <= m; i++) {
        int u, v, d;
        scanf("%d %d %d", &u, &v, &d);
        if (u != v) {
            f[u][v] = std::min(f[u][v], d);
            f[v][u] = std::min(f[v][u], d);
        }
    }

    int ans = INF;
    memcpy(g, f, sizeof(f));
    for (int k = 1; k <= n; k++) {
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                if (i != j && j != k && i != k && f[i][k] < INF && f[k][j] < INF) ans = std::min(ans, g[i][j] + f[i][k] + f[k][j]);
                g[i][j] = std::min(g[i][j], g[i][k] + g[k][j]);
            }
        }
    }

    if (ans == INF) puts("No solution.");
    else printf("%d\n", ans);

    return 0;
}