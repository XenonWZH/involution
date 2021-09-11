// P1387 最大正方形
// WzhDnwzWzh

#include <iostream>
#include <cstring>

const int MAXN = 100;

int main() {
    int n, m;
    static int squ[MAXN + 1][MAXN + 1];

    std::cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            std::cin >> squ[i][j];
        }
    }

    int ans = 0;
    static int sum[MAXN + 1][MAXN + 1];
    memset(sum, 0, sizeof(sum));
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (squ[i][j] == 1) {
                sum[i][j] = std::min(std::min(sum[i - 1][j] , sum[i][j - 1]), sum[i - 1][j - 1]) + 1;
                if (sum[i][j] > ans) {
                    ans = sum[i][j];
                }
            }
        }
    }

    std::cout << ans << std::endl;
    return 0;
}
