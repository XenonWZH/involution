#include <cstdio>
#include <queue>
#include <stack>
#include <vector>
#include <map>

const int MAXN = 100000;

int n, m;
std::vector<int> G[MAXN + 1];
int dfn[MAXN + 1], low[MAXN + 1], ts;
std::stack<int> stk;
bool ins[MAXN + 1];
int cnt, c[MAXN + 1], in[MAXN + 1];
std::vector<int> scc[MAXN + 1];
std::vector<int> GG[MAXN + 1];
int vis[MAXN + 1];
std::map<int, int> mp[MAXN + 1];

void tarjan(int u) {
    dfn[u] = low[u] = ++ts;
    stk.push(u);
    ins[u] = true;
    for (int v : G[u]) {
        if (!dfn[v]) {
            tarjan(v);
            low[u] = std::min(low[u], low[v]);
        } else if (ins[v])
            low[u] = std::min(low[u], dfn[v]);
    }
    if (dfn[u] == low[u]) {
        cnt++;
        int v;
        do {
            v = stk.top();
            stk.pop();
            ins[v] = false;
            c[v] = cnt, scc[cnt].push_back(v);
        } while (u != v);
    }
}

int main() {
    scanf("%d %d", &n, &m);
    for (int i = 1; i <= m; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        G[u].push_back(v);
    }

    if (n == 1) {
        printf("1.000000\n");
        return 0;
    }

    for (int i = 1; i <= n; i++) {
        if (!dfn[i]) {
            tarjan(i);
        }
    }

    for (int u = 1; u <= n; u++) {
        for (int v : G[u]) {
            if (c[u] != c[v] && !mp[c[u]][c[v]]) {
                GG[c[u]].push_back(c[v]);
                in[c[v]]++;
                mp[c[u]][c[v]] = true;
            }
        }
    }

    int cnts = 0;
    bool check = true;
    for (int u = 1; u <= cnt; u++) {
        if (!in[u]) cnts++;
        if (in[u] || scc[u].size() > 1) continue;
        if (check) {
            bool flag = true;
            for (int v : GG[u]) flag &= (in[v] > 1);
            if (flag) cnts--, check = false;
        }
    }
    printf("%.6lf", 1.0 * (n - cnts) / n);

    return 0;
}