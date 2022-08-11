#include <cstdio>
#include <cstring>
#include <algorithm>

const int MAXN = 105;
const int INF = 0x3f3f3f3f;

int n, L, R;
int a[MAXN + 1];
int sum[MAXN + 1];
int f[MAXN + 1][MAXN + 1][MAXN + 1];

inline void dp() {
    for (int l = 1; l <= n; l++) {
        for (int r = 1; r <= n; r++) {
            for (int k = 1; k <= n; k++) {
                f[l][r][k] = INF;
            }
        }
    }
    for (int i = 1; i <= n; i++) f[i][i][1] = 0;

    for (int d = 0; d < n; d++) {
        for (int l = 1; l + d <= n; l++) {
            int r = l + d;
            if (d == 0) {
                f[l][r][1] = 0;
            } else {
                for (int k = 2; k <= n; k++) {
                    for (int mid = l; mid < r; mid++) {
                        f[l][r][k] = std::min(f[l][r][k], f[l][mid][1] + f[mid + 1][r][k - 1]);
                    }

                    if (k >= L && k <= R) {
                        f[l][r][1] = std::min(f[l][r][1], f[l][r][k] + sum[r] - sum[l - 1]);
                    }
                }
            }
        }
    }
}

int main() {
    while (scanf("%d %d %d", &n, &L, &R) != EOF) {
        sum[0] = 0;
        for (int i = 1; i <= n; i++) {
            scanf("%d", &a[i]);
            sum[i] = sum[i - 1] + a[i];
        }

        dp();

        printf("%d\n", f[1][n][1] == INF ? 0 : f[1][n][1]);
    }

    return 0;
}