#include <cstdio>
#include <cstring>
#include <iostream>
#include <vector>
#include <queue>

typedef long long ll;
const int MAXN = 100000;

int n, m, s;
std::vector< std::pair<ll, int> > e[MAXN + 1];
long long dis[MAXN + 1];
bool vis[MAXN + 1];

void dijkstra() {
    memset(dis, 0x3f, sizeof(dis));
    memset(vis, false, sizeof(vis));
    dis[s] = 0;

    static std::priority_queue< std::pair<ll, int>, std::vector< std::pair<ll, int> >,
                                std::greater< std::pair<ll, int> > > q;
    q.push( std::make_pair(0, s) );

    while (!q.empty()) {
        long long d = q.top().first;
        int u = q.top().second;

        q.pop();
        if (vis[u]) continue;
        vis[u] = true;
        for (auto ed : e[u]) {
            int v = ed.first;
            long long w = ed.second;
            if (dis[v] == -1 || d + w < dis[v]) {
                dis[v] = d + w;
                q.push( std::make_pair(dis[v], v) );
            }
        }
    }
}

int main() {
    std::cin >> n >> m >> s;
    for (int i = 0, x, y, z; i < m; i++) {
        std::cin >> x >> y >> z;
        e[x].push_back( std::make_pair(y, z) );
    }

    dijkstra();

    for (int i = 1; i <= n; i++) {
        printf("%lld ", dis[i]);
    }

    std::cout << std::endl;
    return 0;
}