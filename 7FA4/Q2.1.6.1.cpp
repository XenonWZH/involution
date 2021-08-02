// Q2.1.6.1. 方格涂色问题3
// WzhDnwzWzh

#include <iostream>
#include <cstring>

using namespace std;

int board[5][5], n, m, s, t, way = 0;

bool isEnd()
{
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            if (board[i][j] == 0)
                return false;
    return true;
}

void dfs(int x, int y)
{
    if (isEnd())
        way++;
    if (x - 1 >= 0)
        if (board[x - 1][y] == 0)
        {
            board[x - 1][y] = 1;
            dfs(x - 1, y);
            board[x - 1][y] = 0;
        }
    if (x + 1 < n)
        if (board[x + 1][y] == 0)
        {
            board[x + 1][y] = 1;
            dfs(x + 1, y);
            board[x + 1][y] = 0;
        }
    if (y - 1 >= 0)
        if (board[x][y - 1] == 0)
        {
            board[x][y - 1] = 1;
            dfs(x, y - 1);
            board[x][y - 1] = 0;
        }
    if (y + 1 < m)
        if (board[x][y + 1] == 0)
        {
            board[x][y + 1] = 1;
            dfs(x, y + 1);
            board[x][y + 1] = 0;
        }
}

int main()
{
    cin >> n >> m >> s >> t;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            cin >> board[i][j];
    board[s - 1][t - 1] = 1;

    dfs(s - 1, t - 1);

    cout << way << endl;
    return 0;
}