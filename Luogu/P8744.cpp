#include <cstdio>
#include <vector>

const int MAXN = 1e5;

int n;
int f[MAXN + 1];
std::vector<int> G[MAXN + 1];

int dfs(int u) {
    int cnt = 0, size = G[u].size();
    for (int v : G[u]) {
        cnt = std::max(cnt, dfs(v) + size);
    }
    return cnt;
}

int main() {
    scanf("%d", &n);
    for (int i = 2; i <= n; i++) {
        int x;
        scanf("%d", &x);
        G[x].push_back(i);
    }

    printf("%d\n", dfs(1));

    return 0;
}