#include <cstring>
#include <iostream>
#include <vector>
#include <queue>

const int MAXN = 500000;

std::vector< std::pair<int, long long> > e[MAXN + 1];
long long dis[MAXN + 1];

inline void add(int from, int to, int ver) {
    e[from].push_back( std::make_pair(to, ver) );
}

bool spfa(int s) {
    static std::queue<int> q;
    static bool vis[MAXN + 1];
    memset(dis, 0x3f, sizeof(dis));
    memset(vis, false, sizeof(vis));
    dis[s] = 0, vis[s] = true;
    q.push(s);

    while (!q.empty()) {
        int u = q.front();
        q.pop(), vis[u] = false;
        for (auto ed : e[u]) {
            int v = ed.first, w = ed.second;
            if (dis[v] > dis[u] + w) {
                dis[v] = dis[u] + w;
                if (!vis[v]) q.push(v), vis[v] = true;
            }
        }
    }

    return true;
}

int main() {
    int n;
    long long l, r;
    static int a[13];

    std::cin >> n >> l >> r;

    int minA = MAXN + 1;
    for (int i = 1; i <= n; i++) {
        std::cin >> a[i];
        minA = std::min(minA, a[i]);
    }

    for (int i = 0; i < minA; i++) {
        for (int j = 1; j <= n; j++) {
            if (a[j] != minA) {
                add(i, (i + a[j]) % minA, a[j]);
            }
        }
    }

    spfa(0);

    long long ans = 0;
    for (int i = 0; i < minA; i++) {
        if (r >= dis[i]) ans += (r - dis[i]) / minA + 1;
        if (l - 1 >= dis[i]) ans -= (l - 1 - dis[i]) / minA + 1;
    }

    std::cout << ans << std::endl;

    return 0;
}