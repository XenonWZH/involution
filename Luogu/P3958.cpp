// P3958 [NOIP2017 提高组] 奶酪
// WzhDnwzWzh

#include <cmath>
#include <cstring>
#include <iostream>
#include <queue>

const int MAXN = 1000;

struct pos {
    int x, y, z;
};

bool dist(pos a, pos b, int r) {
    if (sqrt(pow(a.x - b.x, 2) + pow(a.y - b.y, 2) + pow(a.z - b.z, 2)) <= 2 * r) return true;
    else return false;
}

bool bfs(pos hole[], int n, int h, int r) {
    static bool vis[MAXN];
    memset(vis, false, sizeof(vis));
    std::queue<pos> nxt;
    for (int i = 0; i < n; i++)
        if (hole[i].z <= r) {
            if (hole[i].z + r >= h) return true;
            nxt.push(hole[i]);
            vis[i] = true;
        }
    while (!nxt.empty()) {
        pos top = nxt.front();
        nxt.pop();
        for (int i = 0; i < n; i++) {
            if (!vis[i] && dist(hole[i], top, r)) {
                if (hole[i].z + r >= h) return true;
                nxt.push(hole[i]);
                vis[i] = true;
            }
        }
    }
    return false;
}

int main() {
    int t;
    std::cin >> t;
    for (int i = 0; i < t; i++) {
        int n, h, r;
        static pos hole[MAXN];
        std::cin >> n >> h >> r;
        for (int j = 0; j < n; j++) std::cin >> hole[j].x >> hole[j].y >> hole[j].z;
        std::cout << (bfs(hole, n, h, r) ? "Yes" : "No") << std::endl;
    }
    return 0;
}