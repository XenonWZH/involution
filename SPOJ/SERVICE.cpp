#include <cstdio>
#include <cstring>
#include <climits>
#include <algorithm>

const int MAXN = 1000, MAXL = 200;

int main() {
    int t;

    scanf("%d", &t);

    while (t--) {
        int l, n;
        static int c[MAXL + 1][MAXL + 1], p[MAXN + 1];

        scanf("%d %d", &l, &n);
        for (int i = 1; i <= l; i++) {
            for (int j = 1; j <= l; j++) {
                scanf("%d", &c[i][j]);
            }
        }
        for (int i = 1; i <= n; i++) scanf("%d", &p[i]);

        static int f[MAXN + 1][MAXL + 1][MAXL + 1];
        memset(f, 0x3f, sizeof(f));
        p[0] = 3;
        f[0][1][2] = 0;

        for (int i = 0; i < n; i++) {
            for (int x = 1; x <= l; x++) {
                for (int y = 1; y <= l; y++) {
                    if (x == y || x == p[i] || y == p[i]) continue;
                    f[i + 1][x][y] = std::min(f[i + 1][x][y], f[i][x][y] + c[p[i]][p[i + 1]]);
                    f[i + 1][x][p[i]] = std::min(f[i + 1][x][p[i]], f[i][x][y] + c[y][p[i + 1]]);
                    f[i + 1][p[i]][y] = std::min(f[i + 1][p[i]][y], f[i][x][y] + c[x][p[i + 1]]);
                }
            }
        }

        int ans = INT_MAX;
        for (int i = 1; i <= l; i++) {
            for (int j = 1; j <= l; j++) {
                ans = std::min(ans, f[n][i][j]);
            }
        }

        printf("%d\n", ans);
    }

    return 0;
}