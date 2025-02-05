#include <cstdio>
#include <vector>

const int MAXN = 1e5;

int main() {
    int n;
    scanf("%d", &n);

    std::vector<int> w(n + 1);
    for (int i = 1; i <= n; i++) scanf("%d", &w[i]);

    std::vector<std::vector<bool>> f(n + 1, std::vector<bool>(2 * MAXN + 10));
    f[0][MAXN] = true;

    for (int i = 1; i <= n; i++) {
        for (int j = 0; j <= 2 * MAXN; j++) {
            f[i][j] = f[i][j] | f[i - 1][j];
            if (j >= w[i]) f[i][j - w[i]] = f[i][j - w[i]] | f[i - 1][j];
            f[i][j + w[i]] = f[i][j + w[i]] | f[i - 1][j];
        }
    }

    int ans = 0;
    for (int i = MAXN + 1; i <= 2 * MAXN; i++) if (f[n][i]) ans++;

    printf("%d\n", ans);

    return 0;
}