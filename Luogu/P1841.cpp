#include <cstdio>
#include <cstring>
#include <iostream>
#include <vector>

const int MAXN = 200, INF = 0x3f3f3f3f;

int n, m;
int f[MAXN + 1][MAXN + 1], way[MAXN + 1][MAXN + 1];

inline void floyd() {
    for (int k = 1; k <= n; k++) {
        for (int x = 1; x <= n; x++) {
            for (int y = 1; y <= n; y++) {
                if (x != k && x != y && y != k) {
                    if (f[x][k] + f[k][y] < f[x][y]) {
                        f[x][y] = f[x][k] + f[k][y];
                        way[x][y] = k;
                    } else if (f[x][k] + f[k][y] == f[x][y]) way[x][y] = 0;
                }
            }
        }
    }
}

int main() {
    std::cin >> n >> m;

    memset(f, 0x3f, sizeof(f));
    for (int i = 1; i <= n; i++) f[i][i] = 0;
    for (int i = 1, x, y, w; i <= m; i++) {
        scanf("%d%d%d", &x, &y, &w);
        f[x][y] = f[y][x] = w;
    }

    memset(way, 0, sizeof(way));
    floyd();

    static bool vis[MAXN + 1];
    memset(vis, false, sizeof(vis));
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (i != j && way[i][j] != 0 && f[i][j] != INF) {
                vis[way[i][j]] = true;
            }
        }
    }

    bool con = true;
    for (int i = 1; i <= n; i++) {
        if (vis[i]) {
            printf("%d ", i);
            con = false;
        }
    }
    if (con) printf("No important cities.");
    printf("\n");

    return 0;
}