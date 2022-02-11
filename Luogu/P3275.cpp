#include <cstdio>
#include <cstring>
#include <iostream>
#include <utility>
#include <vector>
#include <queue>

const int MAXN = 100000, INF = 0x3f3f3f3f;

int n, k, cnt[MAXN + 1];
std::vector< std::pair<int, int> > e[MAXN + 1];
long long dis[MAXN + 1];
bool vis[MAXN + 1];
std::queue<int> q;

bool SPFA() {
    memset(dis, -0x3f, sizeof(dis));
    memset(vis, false, sizeof(vis));
    memset(cnt, 0, sizeof(cnt));
    dis[0] = 0, vis[0] = true;
    q.push(0);

    while (!q.empty()) {
        int u = q.front();
        q.pop();
        vis[u] = false;

        for (auto ed : e[u]) {
            if (dis[ed.first] < dis[u] + ed.second) {
                dis[ed.first] = dis[u] + ed.second;
                cnt[ed.first] = cnt[u] + 1;
                if (cnt[ed.first] >= n + 1) return false;
                if (!vis[ed.first]) {
                    q.push(ed.first);
                    vis[ed.first] = true;
                }
            }
        }
    }

    return true;
}

int main() {
    std::cin >> n >> k;

    for (int i = 0; i < k; i++) {
        int x, a, b;
        scanf("%d%d%d", &x, &a, &b);

        if (x == 1) {
            e[a].push_back( std::make_pair(b, 0) );
            e[b].push_back( std::make_pair(a, 0) );
        } else if (x == 2) {
            if (a == b) {
                std::cout << "-1" << std::endl;
                return 0;
            } else e[a].push_back( std::make_pair(b, 1) );
        }else if (x == 3) e[b].push_back( std::make_pair(a, 0) );
        else if (x == 4) {
            if (a == b) {
                std::cout << "-1" << std::endl;
                return 0;
            } else e[b].push_back( std::make_pair(a, 1) );
        }
        else e[a].push_back( std::make_pair(b, 0) );
    }

    for (int i = 1; i <= n; i++) e[0].push_back( std::make_pair(i, 0) );

    if (SPFA()) {
        int minn = INF;
        long long sum = 0;
        for (int i = 1; i <= n; i++) {
            if (minn > dis[i]) minn = dis[i];
            sum += dis[i];
        }
        sum += (long long)n * (1 - minn);
        std::cout << sum << std::endl;
    } else std::cout << "-1" << std::endl;

    return 0;
}