#include <cstdio>
#include <iostream>
#include <set>
#include <bitset>

const int MAXN = 5000;

int n;
std::bitset<2 * MAXN + 1> e[2 * MAXN + 1];
std::bitset<2 * MAXN + 1> f[2 * MAXN + 1];

int main() {
    freopen("discuss.in", "r", stdin);
    freopen("discuss.out", "w", stdout);

    int t;

    std::cin >> t;

    while (t--) {
        std::cin >> n;

        for (int i = 1; i <= 2 * n; i++) {
            f[i] = 0;
            e[i] = 0;
            f[i][i] = 1;
        }

        for (int i = 1, k; i <= n; i++) {
            scanf("%d", &k);
            for (int j = 0, x; j < k; j++) {
                scanf("%d", &x);
                e[i][n + x] = 1;
                f[i][n + x] = 1;
                f[n + x][i] = 1;
            }
        }

        for (int k = 1; k <= 2 * n; k++)
            for (int i = 1; i <= 2 * n; i++)
                if (f[i][k]) f[i] = f[i] | f[k];

        bool con = true;
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                if (f[i][j] && !(e[i][j]) && i != j && ((e[i] | e[j]) != e[i]) && ((e[i] | e[j]) != e[j]) && ((e[i] & e[j]) != 0)) {
                    con = false;
                    printf("YES\n%d %d\n", i, j);
                    goto endd;
                }
            }
        }

endd:
        if (con) printf("NO\n");
    }

    fclose(stdin);
    fclose(stdout);
    return 0;
}