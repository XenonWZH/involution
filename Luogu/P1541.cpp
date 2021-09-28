// P1541 [NOIP2010 提高组] 乌龟棋
// WzhDnwzWzh

#include <cstring>
#include <iostream>
using namespace std;

int main() {
    int n, m, a[350], b[5];
    memset(b, 0, sizeof(b));

    cin >> n >> m;
    for (int i = 0; i < n; i++) cin >> a[i];
    for (int tmp, j = 0; j < m; j++) {
        cin >> tmp;
        b[tmp]++;
    }

    static int dp[40][40][40][40];
    memset(dp, 0, sizeof(dp));
    dp[0][0][0][0] = a[0];
    dp[1][0][0][0] = a[1];
    dp[0][1][0][0] = a[2];
    dp[0][0][1][0] = a[3];
    dp[0][0][0][1] = a[4];
    for (int i = 0; i <= b[1]; i++) {
        for (int j = 0; j <= b[2]; j++) {
            for (int k = 0; k <= b[3]; k++) {
                for (int l = 0; l <= b[4]; l++) {
                    if (i > 0) dp[i][j][k][l] = max(dp[i][j][k][l], dp[i - 1][j][k][l] + a[i + j * 2 + k * 3 + l * 4]);
                    if (j > 0) dp[i][j][k][l] = max(dp[i][j][k][l], dp[i][j - 1][k][l] + a[i + j * 2 + k * 3 + l * 4]);
                    if (k > 0) dp[i][j][k][l] = max(dp[i][j][k][l], dp[i][j][k - 1][l] + a[i + j * 2 + k * 3 + l * 4]);
                    if (l > 0) dp[i][j][k][l] = max(dp[i][j][k][l], dp[i][j][k][l - 1] + a[i + j * 2 + k * 3 + l * 4]);
                }
            }
        }
    }

    cout << dp[b[1]][b[2]][b[3]][b[4]] << endl;
    return 0;
}