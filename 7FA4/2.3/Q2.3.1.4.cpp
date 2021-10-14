// Q2.3.1.4. 背包问题：不超过的01背包（输出方案）
// WzhDnwzWzh

#include <cstring>
#include <iostream>
#include <vector>

const int MAXN = 100, MAXM = 10000;

int main() {
    int n, M;

    std::cin >> n >> M;
    static int m[MAXN + 5], v[MAXN + 5];
    for (int i = 1; i <= n; i++) std::cin >> m[i] >> v[i];

    static int dp[MAXN + 5][MAXM + 5];
    std::vector<int> way;
    memset(dp, 0, sizeof(dp)); 
    for (int i = n; i >= 1; i--) {
        for (int j = 0; j <= M; j++) {
            dp[i][j] = dp[i + 1][j];
            if (j > m[i]) dp[i][j] = std::max(dp[i][j], dp[i + 1][j - m[i]] + v[i]);
        }
    }

    std::cout << dp[1][M] << std::endl;

    int tmp = M;
    for (int i = 1; i <= n; i++) {
        if (tmp >= m[i] && dp[i][tmp] == dp[i + 1][tmp - m[i]] + v[i]) {
            tmp -= m[i];
            std::cout << i << " ";
        }
    }

    std::cout << std::endl;
    return 0;
}