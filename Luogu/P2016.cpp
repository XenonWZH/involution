#include <cstdio>
#include <vector>

const int MAXN = 1500;

std::vector<int> G[MAXN];
int f[MAXN][2];

int dp(int u, int fa, int w) {
    if (f[u][w]) return f[u][w];
    if (w) {
        f[u][w] = 1;
        for (int v : G[u]) {
            if (v == fa) continue;
            f[u][w] += std::min(dp(v, u, 0), dp(v, u, 1));
        }
    } else {
        f[u][w] = 0;
        for (int v : G[u]) {
            if (v == fa) continue;
            f[u][w] += dp(v, u, 1);
        }
    }
    return f[u][w];
}

int main() {
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        int u, m;
        scanf("%d %d", &u, &m);
        while (m--) {
            int v;
            scanf("%d", &v);
            G[u].push_back(v);
            G[v].push_back(u);
        }
    }

    printf("%d\n", std::min(dp(0, 0, 0), dp(0, 0, 1)));

    return 0;
}