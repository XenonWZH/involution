#include <cstdio>
#include <climits>
#include <vector>

void print(std::vector<std::vector<int>> &g, int l, int r) {
    if (l <= r) printf("%d ", g[l][r]);
    if (l < r) {
        print(g, l, g[l][r] - 1);
        print(g, g[l][r] + 1, r);
    }
}

int main() {
    int n;
    scanf("%d", &n);

    std::vector<int> a(n + 1);
    for (int i = 1; i <= n; i++) scanf("%d", &a[i]);

    std::vector<std::vector<int>> f(n + 2, std::vector<int>(n + 2, 1));
    std::vector<std::vector<int>> g(n + 2, std::vector<int>(n + 2, 0));
    for (int i = 1; i <= n; i++) f[i][i] = a[i], g[i][i] = i;

    for (int len = 2; len <= n; len++) {
        for (int l = 1; l + len - 1 <= n; l++) {
            int r = l + len - 1;
            for (int i = l; i <= r; i++) {
                if (f[l][i - 1] * f[i + 1][r] + a[i] > f[l][r]) {
                    f[l][r] = std::max(f[l][r], f[l][i - 1] * f[i + 1][r] + a[i]);
                    g[l][r] = i;
                }
            }
        }
    }

    printf("%d\n", f[1][n]);
    print(g, 1, n);
    putchar('\n');

    return 0;
}