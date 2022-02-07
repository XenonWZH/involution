#include <cstdio>
#include <cstring>
#include <iostream>

const int MAXN = 200000;

int kids[MAXN + 1], num[MAXN + 1], n, minn = 2 * MAXN;
bool vis[MAXN + 1];

void dfs(int pos, int step) {
    if (vis[pos]) {
        for (int i = 0; i < step; i++)
            if (num[i] == pos) {
                if (step - i < minn) minn = step - i;
                return;
            }
    } else {
        vis[pos] = true;
        num[step] = pos;
        dfs(kids[pos], step + 1);
    }
}

int main()
{
    memset(vis, false, sizeof(vis));

    std::cin >> n;
    for (int i = 1; i <= n; i++) scanf("%d", &kids[i]);

    for (int i = 1; i <= n; i++) dfs(i, 0);

    std::cout << minn << std::endl;

    return 0;
}