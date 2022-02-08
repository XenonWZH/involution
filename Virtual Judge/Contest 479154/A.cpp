#include <cstring>
#include <iostream>
#include <vector>
#include <queue>

const int MAXN = 10000, INF = MAXN * MAXN + 10;

int n, m, s, t;
static std::vector<int> e[MAXN + 1], eRev[MAXN + 1];

bool tmpVis[MAXN + 1], canVis[MAXN + 1], vis[MAXN + 1];
int ans = MAXN * MAXN + 10;

void dfsVis(int pos) {
    tmpVis[pos] = vis[pos] = true;
    for (int each : eRev[pos]) {
        if (!vis[each]) {
            dfsVis(each);
        }
    }
}

void bfsAns() {
    static std::queue< std::pair<int, int> > que;
    que.push( std::make_pair(s, 0) );
    vis[s] = true;

    while (!que.empty()) {
        if (que.front().first == t) {
            ans = que.front().second;
            return;
        }
        for (int each : e[ que.front().first ]) {
            if (!vis[each] && canVis[each]) {
                vis[each] = true;
                que.push( std::make_pair(each, que.front().second + 1) );
            }
        }
        que.pop();
    }
}

int main() {
    std::cin >> n >> m;
    for (int i = 0, x, y; i < m; i++) {
        scanf("%d%d", &x, &y);
        e[x].push_back(y);
        eRev[y].push_back(x);
    }
    std::cin >> s >> t;

    memset(canVis, false, sizeof(canVis));
    memset(tmpVis, false, sizeof(tmpVis));
    memset(vis, false, sizeof(vis));
    dfsVis(t);
    for (int i = 1; i <= n; i++) {
        bool con = true;
        for (int each : e[i]) {
            if (!tmpVis[each]) {
                con = false;
            }
        }
        if (con) canVis[i] = true;
    }

    memset(vis, false, sizeof(vis));
    bfsAns();

    std::cout << (ans == INF ? -1 : ans) << std::endl;

    return 0;
}