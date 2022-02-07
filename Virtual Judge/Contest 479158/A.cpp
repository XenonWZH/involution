#include <cstdio>
#include <cstring>
#include <cmath>
#include <iostream>
#include <vector>

const int MAXN = 1000000;

int n;
std::vector< std::pair<int, int> > e[MAXN + 1];

long long size[MAXN + 1], ans = 0;
bool vis[MAXN + 1];

void dfs(int x) {
    vis[x] = true;
    for (auto each : e[x]) {
        if (!vis[each.first]) {
            dfs(each.first);
            size[x] += size[each.first];
            ans += (long long)(abs(2 * size[each.first] - n)) * each.second;
        }
    }
}

int main() {
    std::cin >> n;
    for (int i = 0; i < n - 1; i++) {
        int x, y, z;
        scanf("%d%d%d", &x, &y, &z);
        e[x].push_back( std::make_pair(y, z) );
        e[y].push_back( std::make_pair(x, z) );
    }

    for (int i = 1; i <= n; i++) size[i] = 1;
    memset(vis, false, sizeof(vis));

    dfs(1);

    std::cout << ans << std::endl;

    return 0;
}