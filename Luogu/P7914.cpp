#include <cstdio>
#include <iostream>

const int MAXN = 500;
const int MOD = 1e9 + 7;

int main() {
    int n, k;
    static char s[MAXN + 1];
    scanf("%d %d", &n, &k);
    scanf("%s", s + 1);

    static long long dp[6][MAXN + 1][MAXN + 1];
    for (int i = 1; i <= n; i++) dp[0][i][i - 1] = 1;

    auto check = [](int l, int r) -> bool {
        return (s[l] == '(' || s[l] == '?') & (s[r] == ')' || s[r] == '?');
    };

    for (int len = 1; len <= n; len++) {
        for (int l = 1; l + len - 1 <= n; l++) {
            int r = l + len - 1;
            if (len <= k) dp[0][l][r] = dp[0][l][r - 1] && (s[r] == '*' || s[r] == '?');
            if (len >= 2) {
                dp[1][l][r] = check(l, r) * (dp[2][l + 1][r - 1] + dp[3][l + 1][r - 1] + dp[4][l + 1][r - 1] + dp[0][l + 1][r - 1]) % MOD;
                for (int i = l; i < r; i++) {
                    (dp[2][l][r] += dp[3][l][i] * dp[0][i + 1][r]) %= MOD;
                    (dp[3][l][r] += (dp[2][l][i] + dp[3][l][i]) * dp[1][i + 1][r]) %= MOD;
                    (dp[4][l][r] += (dp[5][l][i] + dp[4][l][i]) * dp[1][i + 1][r]) %= MOD;
                    (dp[5][l][r] += dp[4][l][i] * dp[0][i + 1][r]) %= MOD;
                }
            }
            (dp[5][l][r] += dp[0][l][r]) %= MOD;
            (dp[3][l][r] += dp[1][l][r]) %= MOD;
        }
    }

    printf("%lld\n", dp[3][1][n]);

    return 0;
}
