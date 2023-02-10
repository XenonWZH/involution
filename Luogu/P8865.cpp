#include <bits/stdc++.h>

#define DBG

namespace XenonWZH {
    const int MAXN = 1000;
    const int MOD = 998244353;

    void solve() {
        int n, m, c, f;
        scanf("%d %d %d %d", &n, &m, &c, &f);

        static char s[MAXN + 1][MAXN + 3];
        for (int i = 1; i <= n; i++) scanf("%s", s[i] + 1);

        std::vector<std::vector<int>> a(n + 1, std::vector<int>(m + 1));
        for (int i = 1; i <= n; i++) for (int j = 1; j <= m; j++) a[i][j] = 1 - (s[i][j] - '0');

        std::vector<std::vector<int>> row(n + 1, std::vector<int>(m + 1));
        for (int i = 1; i <= n; i++) {
            row[i][m] = a[i][m];
            for (int j = m - 1; j >= 1; j--) {
                if (a[i][j]) row[i][j] = row[i][j + 1] + 1;
                else row[i][j] = 0;
            }
        }

        std::vector<std::vector<long long>> pre(n + 1, std::vector<long long>(m + 1));
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                pre[i][j] = row[i][j] - 1;
            }
        }
        for (int i = 2; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                if (pre[i][j] != -1 && pre[i - 1][j] != -1) {
                    pre[i][j] = (pre[i][j] + pre[i - 1][j]) % MOD;
                }
            }
        }

        std::vector<std::vector<int>> col(n + 1, std::vector<int>(m + 1));
        for (int i = 1; i <= m; i++) {
            col[n][i] = 0;
            for (int j = n - 1; j >= 1; j--) {
                if (a[j + 1][i]) col[j][i] = col[j + 1][i] + 1;
                else col[j][i] = 0;
            }
        }

        long long vc = 0, vf = 0;
        for (int i = 3; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                if (a[i][j] && a[i - 1][j] && pre[i - 2][j] != -1) {
                    vc = (vc + (row[i][j] - 1) * pre[i - 2][j] % MOD) % MOD;
                    vf = (vf + (row[i][j] - 1) * pre[i - 2][j] % MOD * col[i][j] % MOD) % MOD;
                }
            }
        }

        printf("%lld %lld\n", (c * vc) % MOD, (f * vf) % MOD);
    }

    int main() {
#ifndef DBG
        freopen("plant.in", "r", stdin);
        freopen("plant.out", "w", stdout);
#endif

        int t, id;
        scanf("%d %d", &t, &id);

        while (t--) solve();

#ifndef DBG
        fclose(stdin);
        fclose(stdout);
#endif

        return 0;
    }
};

int main() {
    return XenonWZH::main();
}