#include <cstdio>
#include <cstring>
#include <algorithm>

const int MAXN = 50;

int main() {
    int n, m;
    static int a[MAXN + 1][MAXN + 1];

    scanf("%d %d", &n, &m);

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            scanf("%d", &a[i][j]);
        }
    }

    static int f[2 * MAXN][MAXN + 1][MAXN + 1];
    memset(f, 0, sizeof(f));
    f[0][1][1] = a[1][1];

    for (int i = 1; i <= n + m - 2; i++) {
        for (int x1 = 1; x1 <= std::min(i + 1, n); x1++) {
            for (int x2 = 1; x2 <= std::min(i + 1, n); x2++) {
                if (x1 == x2) {
                    f[i][x1][x2] = std::max(f[i][x1][x2], f[i - 1][x1 - 1][x2 - 1] + a[x1][i + 2 - x1]);
                    f[i][x1][x2] = std::max(f[i][x1][x2], f[i - 1][x1 - 1][x2] + a[x1][i + 2 - x1]);
                    f[i][x1][x2] = std::max(f[i][x1][x2], f[i - 1][x1][x2 - 1] + a[x1][i + 2 - x1]);
                    f[i][x1][x2] = std::max(f[i][x1][x2], f[i - 1][x1][x2] + a[x1][i + 2 - x1]);
                } else {
                    f[i][x1][x2] = std::max(f[i][x1][x2], f[i - 1][x1 - 1][x2 - 1] + a[x1][i + 2 - x1] + a[x2][i + 2 - x2]);
                    f[i][x1][x2] = std::max(f[i][x1][x2], f[i - 1][x1 - 1][x2] + a[x1][i + 2 - x1] + a[x2][i + 2 - x2]);
                    f[i][x1][x2] = std::max(f[i][x1][x2], f[i - 1][x1][x2 - 1] + a[x1][i + 2 - x1] + a[x2][i + 2 - x2]);
                    f[i][x1][x2] = std::max(f[i][x1][x2], f[i - 1][x1][x2] + a[x1][i + 2 - x1] + a[x2][i + 2 - x2]);
                }
            }
        }
    }

    printf("%d\n", f[n + m - 2][n][n]);

    return 0;
}