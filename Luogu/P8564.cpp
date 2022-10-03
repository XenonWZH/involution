#include <cstdio>
#include <cstring>
#include <iostream>
#include <vector>

const int MAXN = 5000;

int n, size[MAXN + 1];
std::vector<int> e[MAXN + 1];
long long f[MAXN + 1], g[MAXN + 1][MAXN + 1];

void dfs(int p, int fa) {
    size[p] = 1;
    g[p][0] = 0;

    for (int i : e[p]) {
        if (i == fa) continue;
        dfs(i, p);

        for (int j = size[p] + size[i]; j > 0; j--) {
            for (int k = std::max(1, j - size[p]); k <= j && k <= size[i] - 1; k++) {
                g[p][j] = std::min(g[p][j], g[i][k] + g[p][j - k]);
            }
        }

        size[p] += size[i];
    }

    for (int i = 0; i < size[p] - 1; i++) g[p][size[p] - 1] = std::min(g[p][size[p] - 1], g[p][i] + f[size[p] - i]);
}

int main() {
    scanf("%d", &n);
    for (int i = 2; i <= n; i++) scanf("%lld", &f[i]);
    for (int i = 1; i < n; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        e[u].push_back(v);
        e[v].push_back(u);
    }

    memset(g, 0x3f, sizeof(g));
    dfs(1, 0);

    printf("%lld", g[1][size[1] - 1]);

    return 0;
}