#include <cstdio>
#include <iostream>
#include <vector>

const int MAXN = 100000;

int n;
std::vector<int> e[MAXN + 1];
int fa[MAXN + 1][25], dep[MAXN + 1];

void getFa(int u, int f) {
    fa[u][0] = f;
    dep[u] = dep[f] + 1;
    for (int i = 1; i <= 20; i++) fa[u][i] = fa[ fa[u][i - 1] ][i - 1];
    for (int v : e[u]) {
        if (v == f) continue;
        getFa(v, u);
    }
}

int lca(int u, int v) {
    if (dep[u] < dep[v]) std::swap(u, v);
    for (int i = 20; i >= 0; i--) {
        if (dep[ fa[u][i] ] >= dep[v] ) {
            u = fa[u][i];
        }
    }
    if (u == v) return u;
    for (int i = 20; i >= 0; i--) {
        if (fa[u][i] != fa[v][i]) {
            u = fa[u][i];
            v = fa[v][i];
        }
    }
    return fa[u][0];
}

int main() {
    std::cin >> n;
    for (int i = 0, x, y; i < n - 1; i++) {
        scanf("%d%d", &x, &y);
        e[x].push_back(y);
        e[y].push_back(x);
    }

    getFa(1, 0);

    int q;
    std::cin >> q;
    while (q--) {
        int x, y;
        scanf("%d%d", &x, &y);

        int root = lca(x, y);

        printf("%d\n", dep[x] + dep[y] - 2 * dep[root]);
    }

    return 0;
}