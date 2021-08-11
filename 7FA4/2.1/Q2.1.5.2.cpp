// Q2.1.5.2. 分组
// WzhDnwzWzh

#include <cstdio>
#include <iostream>
#include <cstring>
#include <string>
#include <set>
#include <algorithm>

using namespace std;

int n, m, u[10000][2];
bool ban[11], vis[11];
set<string> answer;
string str = "";

void A(int num)
{
    if (num == n)
    {
        cout << str << endl;
        return;
    }
    str[num] = '0';
    A(num + 1);
    str[num] = '1';
    A(num + 1);
}

void dfs()
{
    string ans;
    bool cpy[11];

    for (int i = 1; i <= n; i++)
        if (!ban[i] && !vis[i])
        {
            vis[i] = true;
            memcpy(cpy, ban, sizeof(ban));
            for (int j = 0; j < m; j++)
            {
                if (u[j][0] == i)
                    ban[u[j][1]] = true;
                if (u[j][1] == i)
                    ban[u[j][0]] = true;
            }
            dfs();
            vis[i] = false;
            memcpy(ban, cpy, sizeof(cpy));
        }

    for (int i = 0; i < m; i++)
        if (!vis[u[i][0]] && !vis[u[i][1]])
            return;
    for (int i = 1; i <= n; i++)
        ans += to_string((int)!vis[i]);
    answer.insert(ans);

}

int main()
{
    memset(ban, false, sizeof(ban));
    memset(vis, false, sizeof(vis));

    cin >> n >> m;
    for (int i = 0; i < m; i++)
        cin >> u[i][0] >> u[i][1];

    if (m == 0)
    {
        for (int i = 0; i < n; i++)
            str += '0';
        A(0);
    }
    else
        dfs();

    set<string>::iterator iter = answer.begin();
    while (iter != answer.end())
    {
        cout << *iter << endl;
        iter++;
    }
    return 0;
}