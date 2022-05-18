#include <algorithm>
#include <cstdio>
#include <cstring>

const int MAXN = 500000, INF = 0x3f3f3f3f;

char s[MAXN + 1];
int dp[MAXN + 1][4], f[MAXN + 1][4], cnt;
int ansMax = 1, ansMin = INF;

void dfs(int x) {
    if (s[x] == '0') {
        f[x][0] = dp[x][0] = 1;
        return;
    }
    dfs(++cnt);

    if (s[x] == '1') {
        dp[x][0] = std::max(dp[x + 1][1], dp[x + 1][2]) + 1;
        dp[x][1] = std::max(dp[x + 1][0], dp[x + 1][2]);
        dp[x][2] = std::max(dp[x + 1][0], dp[x + 1][1]);

        f[x][0] = std::min(f[x + 1][1], f[x + 1][2]) + 1;
        f[x][1] = std::min(f[x + 1][0], f[x + 1][2]);
        f[x][2] = std::min(f[x + 1][0], f[x + 1][1]);
    } else {
        int k = ++cnt;
        dfs(k);
        dp[x][0] =
            std::max(dp[x + 1][1] + dp[k][2], dp[x + 1][2] + dp[k][1]) + 1;
        dp[x][1] = std::max(dp[x + 1][0] + dp[k][2], dp[x + 1][2] + dp[k][0]);
        dp[x][2] = std::max(dp[x + 1][0] + dp[k][1], dp[x + 1][1] + dp[k][0]);

        f[x][0] = std::min(f[x + 1][1] + f[k][2], f[x + 1][2] + f[k][1]) + 1;
        f[x][1] = std::min(f[x + 1][0] + f[k][2], f[x + 1][2] + f[k][0]);
        f[x][2] = std::min(f[x + 1][0] + f[k][1], f[x + 1][1] + f[k][0]);
    }

    ansMax = std::max(ansMax, dp[x][0]);
}
int main() {
    scanf("%s", s + 1);

    dfs(++cnt);

    ansMin = std::min(f[1][0], std::min(f[1][1], f[1][2]));
    printf("%d %d\n", ansMax, ansMin);

    return 0;
}
