// Q2.1.5.1. 方格涂色问题
// WzhDnwzWzh

#include <iostream>

using namespace std;

int n;
char ans[21];

void dfs(int num)
{
    if (num >= n)
    {
        for (int i = 0; i < n; i++)
            cout << ans[i];
        cout << endl;
        return;
    }
    ans[num] = 'B';
    dfs(num + 1);
    if (num == 0 || ans[num - 1] == 'B')
    {
        ans[num] = 'R';
        dfs(num + 1);
    }
}

int main()
{
    cin >> n;
    dfs(0);
    return 0;
}