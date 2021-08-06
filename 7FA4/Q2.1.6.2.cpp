// Q2.1.6.2. 有障碍的八皇后问题
// WzhDnwzWzh

#include <iostream>
#include <cstring>

using namespace std;

int queen[9], n, m, ans = 0;
bool ban[9][9];

bool able(int x, int y)
{
    if (ban[x][y])
        return false;
    for (int i = 1; i < x; i++)
        if (queen[i] == y || i + queen[i] == x + y || i - queen[i] == x - y)
            return false;
    return true;
}

void dfs(int x)
{
    if (x > n)
    {
        ans++;
        return;
    }
    for (int i = 1; i <= n; i++)
    {
        if (able(x, i))
        {
            queen[x] = i;
            dfs(x + 1);
        }
    }
}

int main()
{
    int x, y;
    memset(queen, 0, sizeof(queen));
    memset(ban, false, sizeof(ban));

    cin >> n >> m;
    for (int i = 0; i < m; i++)
    {
        cin >> x >> y;
        ban[x][y] = true;
    }

    dfs(1);

    cout << ans << endl;
    return 0;
}