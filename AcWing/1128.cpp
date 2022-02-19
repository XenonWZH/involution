#include <cstdio>
#include <cstring>
#include <iostream>
#include <utility>
#include <vector>

const int MAXN = 100, INF = 0x3f3f3f3f;

int n;
std::vector< std::pair<int, int> > e[MAXN + 1];
int dis[MAXN + 1];
bool vis[MAXN + 1];

void dijkstra(int s) {
    memset(dis, 0x3f, sizeof(dis));
    memset(vis, false, sizeof(vis));
    dis[s] = 0;

    for (int i = 1; i <= n; i++) {
        int u = 0, mind = INF;
        for (int j = 1; j <= n; j++) {
            if (!vis[j] && dis[j] < mind) {
                u = j;
                mind = dis[j];
            }
        }
        vis[u] = true;
        for (auto ed : e[u]) {
            int v = ed.first, w = ed.second;
            if (dis[v] > dis[u] + w) dis[v] = dis[u] + w;
        }
    }
}

int main() {
    int m;

    std::cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int x, y, z;
        scanf("%d%d%d", &x, &y, &z);
        e[x].push_back( std::make_pair(y, z) );
        e[y].push_back( std::make_pair(x, z) );
    }

    dijkstra(1);

    int ans = 0;
    for (int i = 1; i <= n; i++) {
        ans = std::max(ans, dis[i]);
        if (dis[i] == INF) {
            std::cout << "-1" << std::endl;
            return 0;
        }
    }

    std::cout << ans << std::endl;

    return 0;
}