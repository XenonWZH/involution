#include <bits/stdc++.h>

namespace XenonWZH {
    void solve() {
        int n;
        long long h;
        scanf("%d %lld", &n, &h);

        std::vector<int> a(n + 1);
        for (int i = 1; i <= n; i++) scanf( "%d", &a[i]);
        std::sort(a.begin() + 1, a.end());

        std::vector<std::array<std::array<long long, 2>, 3>> f(n + 1);
        for (int i = 0; i <= n; i++) {
            for (int j = 0; j <= 2; j++) {
                for (int k = 0; k <= 1; k++) {
                    f[i][j][k] = LLONG_MIN;
                }
            }
        }
        f[0][2][1] = h;

        for (int i = 0; i <= n; i++) {
            for (int j = 2; j >= 0; j--) {
                for (int k = 1; k >= 0; k--) {
                    if (f[i][j][k] != LLONG_MIN) {
                        if (j > 0) f[i][j - 1][k] = std::max(f[i][j - 1][k], 2 * f[i][j][k]);
                        if (k > 0) f[i][j][k - 1] = std::max(f[i][j][k - 1], 3 * f[i][j][k]);
                        if (a[i] >= f[i][j][k]) f[i][j][k] = LLONG_MIN;
                        else if (i < n) f[i + 1][j][k] = std::max(f[i + 1][j][k], f[i][j][k] + a[i] / 2);
                    }
                }
            }
        }

        int ans = 0;
        for (int i = 0; i <= n; i++) {
            for (int j = 0; j <= 2; j++) {
                for (int k = 0; k <= 1; k++) {
                    if (f[i][j][k] != LLONG_MIN) {
                        ans = std::max(ans, i);
                    }
                }
            }
        }

        printf("%d\n", ans);
    }

    int main() {
        int t;

        scanf("%d", &t);

        while (t--) solve();

        return 0;
    }
}

int main() {
    return XenonWZH::main();
}