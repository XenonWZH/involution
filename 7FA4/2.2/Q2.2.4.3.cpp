// Q2.2.4.3. 魔方大厦
// WzhDnwzWzh

#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>

using namespace std;

int n, p, f[201][201][201], sol = 0;
bool vis[201][201][201];
int way[201][201][201];

inline int read()
{
    int x = 0, w = 1;
    char ch = 0;
    while (ch < '0' || ch > '9')
    {
        if (ch == '-') w = -1;
        ch = getchar();
    }
    while (ch >= '0' && ch <= '9')
    {
        x = x * 10 + (ch - '0');
        ch = getchar();
    }
    return x * w;
}

int dfs(int x, int y, int z)
{
    if (way[x][y][z] != 0)
        return way[x][y][z];
    way[x][y][z] = (way[x][y][z] + 1) % p;
    vis[x][y][z] = true;
    if (x + 1 < n)
        if (f[x + 1][y][z] > f[x][y][z])
        {
            way[x][y][z] += dfs(x + 1, y, z);
            way[x][y][z] %= p;
        }
    if (x - 1 >= 0)
        if (f[x - 1][y][z] > f[x][y][z])
        {
            way[x][y][z] += dfs(x - 1, y, z);
            way[x][y][z] %= p;
        }
    if (y + 1 < n)
        if (f[x][y + 1][z] > f[x][y][z])
        {
            way[x][y][z] += dfs(x, y + 1, z);
            way[x][y][z] %= p;
        }
    if (y - 1 >= 0)
        if (f[x][y - 1][z] > f[x][y][z])
        {
            way[x][y][z] += dfs(x, y - 1, z);
            way[x][y][z] %= p;
        }
    if (z + 1 < n)
        if (f[x][y][z + 1] > f[x][y][z])
        {
            way[x][y][z] += dfs(x, y, z + 1);
            way[x][y][z] %= p;
        }
    if (z - 1 >= 0)
        if (f[x][y][z - 1] > f[x][y][z])
        {
            way[x][y][z] += dfs(x, y, z - 1);
            way[x][y][z] %= p;
        }
    return way[x][y][z];
}

int main()
{
    memset(vis, 0, sizeof(vis));
    memset(way, 0, sizeof(way));

    n = read();
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            for (int k = 0; k < n; k++)
                f[i][j][k] = read();
    p = read();

    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            for (int k = 0; k < n; k++)
                dfs(i, j, k);

    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            for (int k = 0; k < n; k++)
            {
                sol += way[i][j][k];
                sol %= p;
            }
    cout << sol << endl;
    return 0;
}