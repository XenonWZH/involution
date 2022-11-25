#include <cstdio>
#include <vector>

const int MOD = 100000000;

int main() {
    int m, n;
    scanf("%d %d", &m, &n);

    std::vector<std::vector<bool>> valid(m + 1, std::vector<bool>(n));
    for (int i = 1; i <= m; i++) {
        for (int j = 0; j < n; j++) {
            int x;
            scanf("%d", &x);
            valid[i][j] = x;
        }
    }

    auto check = [&](int p, int now, int bef) {
        for (int i = 0; i < n; i++) {
            if (((now >> i) & 1) > valid[p][i]) {
                return false;
            }
        }
        for (int i = 0; i < n; i++) {
            if (((now >> i) & 1) && ((bef >> i) & 1)) {
                return false;
            }
        }
        for (int i = 0; i < n - 1; i++) {
            if (((now >> i) & 1) && ((now >> (i + 1)) & 1)) {
                return false;
            }
        }
        return true;
    };

    std::vector<std::vector<long long>> f(m + 1, std::vector<long long>(1 << n, 0));
    f[0][0] = 1;
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < (1 << n); j++) {
            for (int k = 0; k < (1 << n); k++) {
                if (check(i + 1, k, j)) {
                    f[i + 1][k] = (f[i + 1][k] + f[i][j]) % MOD;
                }
            }
        }
    }

    long long ans = 0;
    for (int i = 0; i < (1 << n); i++) ans = (ans + f[m][i]) % MOD;

    printf("%lld\n", ans);

    return 0;
}