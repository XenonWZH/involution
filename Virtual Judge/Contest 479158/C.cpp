#include <iostream>
#include <vector>

const int MAXN = 100001;

int n, d = 0;
int d1[MAXN], d2[MAXN];
std::vector<int> E[MAXN];

void dfs(int u, int fa) {
    d1[u] = d2[u] = 0;
    for (int v : E[u]) {
        if (v == fa) continue;
        dfs(v, u);
        int t = d1[v] + 1;
    if (t > d1[u])
        d2[u] = d1[u], d1[u] = t;
    else if (t > d2[u])
        d2[u] = t;
    }
    d = std::max(d, d1[u] + d2[u]);
}

int main() {
    scanf("%d", &n);
    for (int i = 1; i < n; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        E[u].push_back(v), E[v].push_back(u);
    }
    dfs(1, 0);
    printf("%d\n", d);
    return 0;
}