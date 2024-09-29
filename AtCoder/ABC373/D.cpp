#include <bits/stdc++.h>

const int MAXN = 2e5;

std::vector<std::pair<int, long long>> G[MAXN + 1];
std::vector<std::pair<int, long long>> H[MAXN + 1];

long long ans[MAXN + 1];
int d[MAXN + 1];
bool vis[MAXN + 1];

void dfs(int u) {
    vis[u] = true;
    for (auto [v, w] : G[u]) {
        if (vis[v]) continue;
        ans[v] = ans[u] + w;
        dfs(v);
    }
    for (auto [v, w] : H[u]) {
        if (vis[v]) continue;
        ans[v] = ans[u] - w;
        dfs(v);
    }
}

int main() {
    int n, m;
    scanf("%d %d", &n, &m);

    for (int i = 0; i < m; i++) {
        int u, v, w;
        scanf("%d %d %d", &u, &v, &w);
        G[u].push_back(std::make_pair(v, w));
        H[v].push_back(std::make_pair(u, w));
    }

    for (int i = 1; i <= n; i++) {
        if (!vis[i]) {
            dfs(i);
        }
    }

    for (int i = 1; i <= n; i++) printf("%lld ", ans[i]);
    puts("");

    return 0;
}