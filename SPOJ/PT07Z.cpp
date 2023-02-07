#include <iostream>
#include <vector>

const int MAXN = 100000;

int n, d = 0;
int head[MAXN + 1], ver[2 * MAXN + 2], nxt[2 * MAXN + 2], tot = 0;
int d1[MAXN + 1], d2[MAXN + 1];

void add(int u, int v) {
    ver[++tot] = v;
    nxt[tot] = head[u];
    head[u] = tot;
}

void dfs(int u, int fa) {
    d1[u] = d2[u] = 0;
    for (int i = head[u]; i; i = nxt[i]) {
        int v = ver[i];
        if (v == fa) continue;
        dfs(v, u);
        int t = d1[v] + 1;
        if (t > d1[u]) d2[u] = d1[u], d1[u] = t;
        else if (t > d2[u]) d2[u] = t;
    }
    d = std::max(d, d1[u] + d2[u]);
}

int main() {
    scanf("%d", &n);
    for (int i = 1; i < n; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        add(u, v);
        add(v, u);
    }

    dfs(1, 0);

    printf("%d\n", d);

    return 0;
}