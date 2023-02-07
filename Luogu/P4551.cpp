#include <cstdio>
#include <algorithm>

const int MAXN = 1000000;
const int LOG_MAXW = 32;

int n;
int head[MAXN + 1], ver[2 * MAXN + 2], nxt[2 * MAXN + 2], edge[2 * MAXN + 2], totEdge;
int d[MAXN + 1];
int trie[MAXN * LOG_MAXW + 1][2], totTrie = 1;
bool end[MAXN + 1];

void add(int u, int v, int w) {
    ver[++totEdge] = v;
    edge[totEdge] = w;
    nxt[totEdge] = head[u];
    head[u] = totEdge;
}

void dfs(int u, int fa) {
    for (int i = head[u]; i; i = nxt[i]) {
        int v = ver[i], w = edge[i];
        if (v == fa) continue;
        d[v] = d[u] ^ w;
        dfs(v, u);
    }
}

void insert(int n) {
    int p = 1;
    for (int i = LOG_MAXW - 1; i >= 0; i--) {
        int ch = (n >> i) & 1;
        if (trie[p][ch] == 0) trie[p][ch] = ++totTrie;
        p = trie[p][ch];
    }
    end[p] = true;
}

int solve(int n) {
    int p = 1, ans = 0;
    for (int i = LOG_MAXW - 1; i >= 0; i--) {
        int ch = (n >> i) & 1;
        if (trie[p][ch ^ 1]) {
            ans += (1 << i);
            p = trie[p][ch ^ 1];
        } else p = trie[p][ch];
    }
    return ans;
}

int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n - 1; i++) {
        int u, v, w;
        scanf("%d %d %d", &u, &v, &w);
        add(u, v, w);
        add(v, u, w);
    }

    dfs(1, 0);
    for (int i = 1; i <= n; i++) insert(d[i]);
    int ans = 0;
    for (int i = 1; i <= n; i++) ans = std::max(ans, solve(d[i]));

    printf("%d\n", ans);

    return 0;
}