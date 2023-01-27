#include <cstdio>
#include <climits>
#include <algorithm>

const int MAXN = 100;

int main() {
    int n;
    scanf("%d", &n);

    static int a[2 * MAXN + 1], s[2 * MAXN + 1];
    for (int i = 1; i <= n; i++) scanf("%d", &a[i]), a[i + n] = a[i];
    for (int i = 1; i <= 2 * n; i++) s[i] = a[i] + s[i - 1];

    static int f[2 * MAXN + 1][2 * MAXN + 1], g[2 * MAXN + 1][2 * MAXN + 1];
    for (int i = 1; i <= 2 * n; i++) f[i][i] = g[i][i] = 0;
    for (int len = 2; len <= 2 * n; len++) {
        for (int l = 1; l + len - 1 <= 2 * n; l++) {
            const int r = l + len - 1;
            f[l][r] = INT_MAX, g[l][r] = 0;

            for (int i = l; i < r; i++) {
                f[l][r] = std::min(f[l][r], f[l][i] + f[i + 1][r] + s[r] - s[l - 1]);
                g[l][r] = std::max(g[l][r], g[l][i] + g[i + 1][r] + s[r] - s[l - 1]);
            }
        }
    }

    int min = INT_MAX, max = 0;
    for (int i = 1; i <= n; i++) min = std::min(min, f[i][i + n - 1]), max = std::max(max, g[i][i + n - 1]);
    printf("%d\n%d\n", min, max);

    return 0;
}