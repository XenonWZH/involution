#include <cstdio>
#include <climits>
#include <iostream>
#include <algorithm>
#include <vector>

const int MAXN = 12;

int main() {
    int n, m;
    static int a[MAXN + 1][MAXN + 1];

    scanf("%d %d", &n, &m);

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            a[i][j] = INT_MAX;
        }
    }
    for (int i = 1; i <= m; i++) {
        int x, y, w;
        scanf("%d %d %d", &x, &y, &w);
        a[x][y] = std::min(a[x][y], w);
        a[y][x] = std::min(a[y][x], w);
    }

    static int expand[1 << MAXN], road[1 << MAXN][MAXN + 1];
    for (int k = 0; k < (1 << n); k++) {
        for (int x = 1; x <= n; x++) {
            road[k][x] = INT_MAX;
        }
    }
    for (int k = 0; k < (1 << n); k++) {
        expand[k] = k;
        for (int x = 1; x <= n; x++) {
            if (k >> (x - 1) & 1) {
                road[k][x] = 0;
                for (int y = 1; y <= n; y++) {
                    if (a[x][y] == INT_MAX) continue;
                    expand[k] |= 1 << (y - 1);
                    road[k][y] = std::min(road[k][y], a[x][y]);
                }
            }
        }
    }

    static std::vector<int> valid[1 << MAXN], cost[1 << MAXN];
    for (int j = 0; j < (1 << n); j++) {
        for (int k = 0; k < j; k++) {
            if ((j & k) == k && (j & expand[k]) == j) {
                valid[j].push_back(k);
                int sum = 0;
                for (int i = 1; i <= n; i++) {
                    if (((j ^ k) >> (i - 1)) & 1) {
                        sum += road[k][i];
                    }
                }
                cost[j].push_back(sum);
            }
        }
    }

    static int f[MAXN + 1][1 << MAXN];
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j < (1 << n); j++) {
            f[i][j] = INT_MAX;
        }
    }
    for (int i = 1; i <= n; i++) f[1][1 << (i - 1)] = 0;
    int ans = f[1][(1 << n) - 1];
    for (int i = 2; i <= n; i++) {
        for (int j = 1; j < 1 << n; j++) {
            for (size_t p = 0; p < valid[j].size(); p++) {
                int k = valid[j][p];
                if (f[i - 1][k] != INT_MAX) {
                    f[i][j] = std::min(f[i][j], f[i - 1][k] + (i - 1) * cost[j][p]);
                }
            }
        }
        ans = std::min(ans, f[i][(1 << n) - 1]);
    }

    printf("%d\n", ans);

    return 0;
}