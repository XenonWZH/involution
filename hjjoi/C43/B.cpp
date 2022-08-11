#include <cstdio>
#include <algorithm>

const int MAXN = 5000;

int main() {
    int t;

    scanf("%d", &t);

    while (t--) {
        int n, len = 0;
        static int a[MAXN + 1];

        scanf("%d", &n);

        static int pos[MAXN + 1];
        for (int i = 1; i <= n; i++) pos[i] = n + 1;

        for (int i = 1; i <= n; i++) {
            scanf("%d", &a[++len]);
            if (a[len] == a[len - 1]) len--;
        }
        n = len;

        static int next[MAXN + 1];
        for (int i = n; i >= 1; i--) {
            next[i] = pos[a[i]];
            pos[a[i]] = i;
        }

        static int f[MAXN + 1][MAXN + 1];
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                f[i][j] = 0;
            }
        }

        for (int d = 0; d < n; d++) {
            for (int l = 1; l + d <= n; l++) {
                int r = l + d;
                f[l][r] = f[l + 1][r];
                int x = next[l];
                while (x <= r) {
                    f[l][r] = std::max(f[l][r], f[l + 1][x - 1] + f[x][r] + 1);
                    x = next[x];
                }
            }
        }

        printf("%d\n", n - 1 - f[1][n]);
    }

    return 0;
}