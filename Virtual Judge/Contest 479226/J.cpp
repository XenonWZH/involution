#include <cstdio>
#include <cstring>
#include <iostream>
#include <vector>

const int MAXN = 10000;

int n;
std::vector< std::pair<int, int> > e[MAXN + 1];
int dis[MAXN + 1];

bool bf() {
    bool con;
    memset(dis, 0x3f, sizeof(dis));
    dis[0] = 0;

    for (int i = 0; i <= n; i++) {
        con = false;
        for (int j = 0; j <= n; j++) {
            for (auto each : e[j]) {
                if (dis[each.first] > dis[j] + each.second) {
                    dis[each.first] = dis[j] + each.second;
                    con = true;
                }
            }
        }

        if (!con) break;
    }

    return con;
}


int main() {
    int m;

    std::cin >> n >> m;
    for (int i = 0, op, a, b, c; i < m; i++) {
        scanf("%d", &op);
        if (op == 1) {
            scanf("%d%d%d", &a, &b, &c);
            e[a].push_back( std::make_pair(b, -c) );
        } else if (op == 2) {
            scanf("%d%d%d", &a, &b, &c);
            e[b].push_back( std::make_pair(a, c) );
        } else {
            scanf("%d%d", &a, &b);
            e[a].push_back( std::make_pair(b, 0) );
            e[b].push_back( std::make_pair(a, 0) );
        }
    }

    // 将0作为超级源点
    for (int i = 1; i <= n; i++) e[0].push_back( std::make_pair(i, 0) );

    std::cout << (bf() ? "No" : "Yes") << std::endl;

    return 0;
}