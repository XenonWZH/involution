#include <bits/stdc++.h>

int main() {
    int n, m;
    scanf("%d %d", &n, &m);

    std::vector<std::vector<int>> f(n + 1, std::vector<int>(n + 1, INT_MAX));
    for (int i = 1; i <= n; i++) f[i][i] = 0;
    for (int i = 1; i <= m; i++) {
        int u, v, w;
        scanf("%d %d %d", &u, &v, &w);
        f[u][v] = std::min(f[u][v], w);
        f[v][u] = std::min(f[v][u], w);
    }

    for (int k = 1; k <= n; k++) {
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                if (f[i][k] != INT_MAX && f[k][j] != INT_MAX) {
                    f[i][j] = std::min(f[i][j], f[i][k] + f[k][j]);
                }
            }
        }
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) printf("%d ", f[i][j]);
        puts("");
    }

    return 0;
}