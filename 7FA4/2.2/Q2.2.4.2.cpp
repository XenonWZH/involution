// Q2.2.4.2. 传纸条2
// WzhDnwzWzh

#include <iostream>
#include <cstring>

using namespace std;

int kids[300001], num[300001], n, ans = 0, maxn = 0;
bool vis[300001];

void dfs(int pos, int step)
{
    if (vis[pos])
    {
        for (int i = 0; i < step; i++)
            if (num[i] == pos)
            {
                ans += step - i;
                if (step - i > maxn)
                    maxn = step - i;
                return;
            }
    }
    else
    {
        vis[pos] = true;
        num[step] = pos;
        dfs(kids[pos], step + 1);
    }
}

int main()
{
    memset(vis, false, sizeof(vis));

    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> kids[i];
    for (int i = 1; i <= n; i++)
        dfs(i, 0);

    cout << ans << " " << maxn << endl;
    return 0;
}