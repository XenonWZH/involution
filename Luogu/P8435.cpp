#include <cstdio>
#include <algorithm>
#include <vector>
#include <stack>

const int MAXN = 2e6;

int n, m;
std::vector<int> G[MAXN + 1];

int dfn[MAXN + 1], low[MAXN + 1];
int ts = 0, root;
std::stack<int> stk;

std::vector<int> dcc[MAXN + 1];
int cnt;

void tarjan(int u) {
    dfn[u] = low[u] = ++ts;
    stk.push(u);
    if (u == root && G[u].empty()) {
        dcc[++cnt].push_back(u);
        return;
    }
    int m = G[u].size();
    for (int i = 0; i < m; i++) {
        int v = G[u][i];
        if (!dfn[v]) {
            tarjan(v);
            low[u] = std::min(low[u], low[v]);
            if (low[v] >= dfn[u]) {
                cnt++;
                int w;
                do {
                    w = stk.top();
                    stk.pop();
                    dcc[cnt].push_back(w);
                } while (w != v);
                dcc[cnt].push_back(u);
            }
        } else low[u] = std::min(low[u], dfn[v]);
    }
}

int main() {
    scanf("%d %d", &n, &m);
    for (int i = 1; i <= m; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        if (u == v) continue;
        G[u].push_back(v);
        G[v].push_back(u);
    }

    for (int i = 1; i <= n; i++) {
        if (!dfn[i]) {
            root = i;
            tarjan(i);
        }
    }

    printf("%d\n", cnt);
    for (int i = 1; i <= cnt; i++) {
        int m = dcc[i].size();
        printf("%d ", m);
        for (int j = 0; j < m; j++) printf("%d ", dcc[i][j]);
        puts("");
    }

    return 0;
}