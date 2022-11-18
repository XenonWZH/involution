#include <algorithm>
#include <climits>
#include <cstdio>
#include <vector>

int main() {
    int n;
    scanf("%d", &n);

    std::vector<long long> a(n + 1);
    std::vector<int> id(n + 1);
    for (int i = 1; i <= n; i++) scanf("%lld", &a[i]);
    std::sort(a.begin() + 1, a.end());
    for (int i = 1; i <= n; i++) a[i] = a[n] - a[i], id[i] = i;

    std::vector<std::vector<long long>> f(62, std::vector<long long>(n + 1, LLONG_MAX));
    f[0][0] = 0;

    std::vector<std::vector<int>> s(2, std::vector<int>(n + 1));
    for (int k = 0; k <= 60; k++) {
        std::sort(id.begin() + 1, id.end(), [&](int x, int y) { return (a[x] & ((1ll << k) - 1)) < (a[y] & ((1ll << k) - 1)); });

        for (int i = 1; i <= n; i++) {
            s[0][i] = s[0][i - 1], s[1][i] = s[1][i - 1];
            s[(a[id[i]] >> k) & 1][i]++;
        }

        for (int i = 0; i <= n; i++) {
            if (f[k][i] != LLONG_MAX) {
                int w = s[1][n - i] + s[0][n] - s[0][n - i];
                int l = s[1][n] - s[1][n - i];

                f[k + 1][l] = std::min(f[k + 1][l], f[k][i] + w);
                w = s[0][n - i] + s[1][n] - s[1][n - i], l = n - s[0][n - i];
                f[k + 1][l] = std::min(f[k + 1][l], f[k][i] + w);
            }
        }
    }

    printf("%lld\n", f[61][0]);

    return 0;
}