// Q2.3.1.4. 背包问题：不超过的01背包（输出方案）
// WzhDnwzWzh

#include <iostream>
#include <cstring>
#include <string>

using namespace std;

int dp[10001], n, M, m, v;
bool way[10001][10001];
string src, des;

int main()
{
    memset(way, false, sizeof(way));
    memset(dp, 0, sizeof(dp));

    cin >> n >> M;
    for (int i = 1; i <= n; i++)
    {
        cin >> m >> v;
        for (int j = M; j >= m; j--)
            if (dp[j - m] + v > dp[j])
            {
                dp[j] = dp[j - m] + v;
                way[j][i] = true;
            }
    }

    cout << dp[M] << endl;
    for (int i = 1; i <= n; i++)
        if (way[M][i])
            cout << i << " ";
    cout << endl;
    return 0;
}