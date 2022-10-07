#include <algorithm>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <queue>
#include <utility>
#include <vector>

const int MAXN = 100000, INF = 200000;

int n, m;
std::vector< std::pair<int, int> > e[MAXN + 1];
int vis[MAXN + 1], ans;
int col[INF + 1];

void bfsK() {
    static std::queue< std::pair<int, int> > qK;
    memset(vis, -1, sizeof(vis));
    qK.push( std::make_pair(n, 0) );
    vis[n] = 0, ans = INF;

    while (!qK.empty()) {
        auto u = qK.front();
        qK.pop();
        if (u.first == 1 && u.second < ans) ans = u.second;
        for (auto ed : e[u.first]) {
            if (vis[ed.first] == -1) {
                vis[ed.first] = u.second + 1;
                qK.push(std::make_pair(ed.first, u.second + 1));
            }
        }
    }
}

void bfsCol() {
    static std::vector<int> qCol;
    static bool mk[MAXN + 1];
    memset(col, 0x3f, sizeof(col));
    memset(mk, false, sizeof(mk));
    qCol.clear();
    qCol.push_back(1);

    int cnt = ans - 1;
    bool flag = true;
    while (cnt >= 0) {
        static std::vector<int> uSet;
        if (flag) {
            uSet.clear();
            for (int each : qCol) uSet.push_back(each);
            qCol.clear();
        }
        flag = true;
        for (int u : uSet) {
            for (auto ed : e[u]) {
                if (vis[ed.first] == cnt) {
                    if (!mk[ed.first]) {
                        if (col[cnt] >= ed.second) {
                            if (col[cnt] > ed.second) qCol.clear();
                            col[cnt] = ed.second;
                            mk[ed.first] = true;
                            flag = false;
                            qCol.push_back(ed.first);
                        }
                    } else if (col[cnt] > ed.second) col[cnt] = ed.second;
                }
            }
        }
        if (flag) {
            cnt--;
            for (int u : uSet) {
                for (auto ed : e[u]) {
                    if (vis[ed.first] == cnt) {
                        if (!mk[ed.first]) {
                            if (col[cnt] >= ed.second) {
                                if (col[cnt] > ed.second) qCol.clear();
                                col[cnt] = ed.second;
                                mk[ed.first] = true;
                                flag = false;
                                qCol.push_back(ed.first);
                            }
                        } else if (col[cnt] > ed.second) col[cnt] = ed.second;
                    }
                }
            }
        }
    }
}

int main() {
    while (std::cin >> n >> m) {
        for (int i = 1; i <= n; i++) e[i].clear();

        for (int i = 0, x, y, z; i < m; i++) {
            scanf("%d%d%d", &x, &y, &z);
            if (x == y) continue;
            e[x].push_back( std::make_pair(y, z) );
            e[y].push_back( std::make_pair(x, z) );
        }

        for (int i = 1; i <= n; i++) std::sort(e[i].begin(), e[i].end());

        bfsK();
        bfsCol();

        std::cout << ans << std::endl;
        for (int i = ans - 1; i >= 0; i--) printf("%d%c", col[i], i == 0 ? '\n' : ' ');
    }

    return 0;
}