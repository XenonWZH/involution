#include <cstdio>
#include <cstring>
#include <iostream>

const int MAXM = 4, MAXN = 200000;

int main() {
    freopen("sort.in", "r", stdin);
    freopen("sort.out", "w", stdout);

    int m, n;
    static int a[MAXM + 1][MAXN + 1];

    std::cin >> m >> n;
    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            scanf("%d", &a[i][j]);
        }
    }

    unsigned long long ans = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            int minn = 200001, maxn = 0;

            for (int k = 1; k <= m; k++) {
                minn = std::min(minn, a[k][i] + a[k][j]);
                maxn = std::max(maxn, a[k][i] + a[k][j]);
            }

            ans += minn + maxn;
        }
    }

    std::cout << ans << std::endl;


    fclose(stdin);
    fclose(stdout);
    return 0;
}