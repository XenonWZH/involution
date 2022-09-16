#include <algorithm>
#include <cstdio>
#include <cstring>
#include <vector>

const int MAXN = 5000;

int n, m;
std::vector<int> e[MAXN + 1];
int edge[MAXN + 1][2];
bool v[MAXN + 1];
int ans[MAXN + 1], res[MAXN + 1];
int from, to, counts;

void dfs(int p, int f) {
    res[++counts] = p;
    v[p] = true;
    for (int t : e[p]) {
        if ((from == p && to == t) || (from == t && to == p) || t == f || v[t])
            continue;
        dfs(t, p);
    }
}

inline int read() {
    int x = 0, w = 1;
    char ch = 0;
    while (ch < '0' || ch > '9') {
        if (ch == '-') w = -1;
        ch = getchar();
    }
    while (ch >= '0' && ch <= '9') {
        x = x * 10 + (ch - '0');
        ch = getchar();
    }
    return x * w;
}

inline bool comp() {
    for (int i = 1; i <= n; i++) {
        if (ans[i] != res[i]) {
            return ans[i] > res[i];
        }
    }
    return false;
}

int main() {
    n = read(), m = read();
    for (int i = 1; i <= m; i++) {
        edge[i][0] = read(), edge[i][1] = read();
        e[edge[i][0]].push_back(edge[i][1]);
        e[edge[i][1]].push_back(edge[i][0]);
    }

    memset(ans, 0x3f, sizeof(ans));
    for (int i = 1; i <= n; i++) std::sort(e[i].begin(), e[i].end());
    if (n == m) {
        for (int i = 1; i <= m; i++) {
            from = edge[i][0], to = edge[i][1], counts = 0;
            memset(res, 0, sizeof(res));
            memset(v, false, sizeof(v));
            dfs(1, 0);
            if (counts == n && comp()) memcpy(ans, res, sizeof(res));
        }
    } else {
        dfs(1, 0);
        memcpy(ans, res, sizeof(res));
    }

    for (int i = 1; i <= n; i++) printf("%d ", ans[i]);
    putchar('\n');

    return 0;
}