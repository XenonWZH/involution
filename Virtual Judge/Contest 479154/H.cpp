#include <cstdio>
#include <cstring>
#include <iostream>
#include <vector>

const int MAXN = 200000;

int n, m;
std::vector<int> e[MAXN + 1];

int vis[MAXN + 1], ans = 0;

int dfs(int pos) {
    if (vis[pos] != 0) return vis[pos];
    int ret = 0;
    for (int each : e[pos]) ret += dfs(each);
    if (ret == 0) return 1;
    vis[pos] = ret;
    return ret;
}

int main() {
    std::cin >> n >> m;

    static bool isDfs[MAXN + 1];
    memset(isDfs, true, sizeof(isDfs));
    for (int i = 0, a, b; i < m; i++) {
        scanf("%d%d", &a, &b);
        e[a].push_back(b);
        isDfs[b] = false;
    }

    memset(vis, 0, sizeof(vis));
    for (int i = 1; i <= n; i++) if (isDfs[i] && e[i].size() > 0) ans += dfs(i);

    std::cout << ans << std::endl;

    return 0;
}