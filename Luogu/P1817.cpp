#include <bits/stdc++.h>
using namespace std;
#define N 10
int n, m;
int ans = 0;
int movex[4] = {1, 0, -1, 0};
int movey[4] = {0, 1, 0, -1};
int vis[N][N];
void dfs(int x, int y) {
    vis[x][y] = 1;
    if (x == 1 || y == m || x == n || y == 1)  //到达另一个边缘点
    {
        ans++;
        vis[x][y] = 0;
        return;
    }
    for (int i = 0; i < 4; ++i) {
        int xx = x + movex[i], yy = y + movey[i];
        if (xx < 1 || yy < 1 || xx > n || yy > m || vis[xx][yy]) continue;
        dfs(xx, yy);
    }
    vis[x][y] = 0;
}
int main() {
    for (int qwq = 1; qwq <= 6; qwq++) {
        for (int wqw = 2; wqw <= 7; wqw++) {
            n = qwq, m = wqw;
            n++;
            m++;  //转换为点图
            memset(vis, 0, sizeof(vis));
            ans = 0;
            for (int i = 2; i < n; ++i)  //这么写就是为了去掉交点
            {
                vis[i][1] = 1;  //手动将出发点设为已访问
                dfs(i, 2);      //然后手动走第一步，防止无效切割
                vis[i][1] = 0;  //回溯
            }
            for (int i = 2; i < m; ++i)  //同上
            {
                vis[1][i] = 1;
                dfs(2, i);
                vis[1][i] = 0;
            }
            printf("if (n == %d && m == %d) puts(\"%d\");\n", n - 1, m - 1, ans);
        }
    }
    return 0;
}