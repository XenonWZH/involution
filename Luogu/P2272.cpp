#include <cstdio>
#include <vector>
#include <stack>
#include <queue>
#include <map>

const int MAXN = 1e5;

int n, m, x;
std::vector<int> G[MAXN + 1];
int dfn[MAXN + 1], low[MAXN + 1], ts;
std::stack<int> stk;
bool ins[MAXN + 1];
int c[MAXN + 1], cnt;
std::vector<int> scc[MAXN + 1];
std::map<int, int> mp[MAXN + 1];
std::vector<int> GC[MAXN + 1];
int in[MAXN + 1];
int f[MAXN + 1];
long long g[MAXN + 1];

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


int dp1(int u) {
    if (f[u]) return f[u];
    f[u] = scc[u].size();
    for (int v : GC[u]) f[u] = std::max(f[u], dp1(v) + (int)scc[u].size());
    return f[u];
}

int main() {
    scanf("%d %d %d", &n, &m, &x);
    for (int i = 1; i <= m; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        G[u].push_back(v);
    }

    for (int i = 1; i <= n; i++) {
        if (!dfn[i]) {
            tarjan(i);
        }
    }

    for (int u = 1; u <= n; u++) {
        for (int v : G[u]) {
            if (c[u] != c[v] && !mp[c[u]][c[v]]) {
                GC[c[u]].push_back(c[v]);
                mp[c[u]][c[v]] = true;
                in[c[v]]++;
            }
        }
    }

    std::queue<int> q;
    for (int i = 1; i <= cnt; i++) {
        if (!in[i]) {
            q.push(i);
            f[i] = scc[i].size();
            g[i] = 1;
        }
    }
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        for (int v : GC[u]) {
            if (f[v] < f[u] + scc[v].size()) {
                f[v] = f[u] + scc[v].size();
                g[v] = g[u];
            } else if (f[v] == f[u] + scc[v].size()) g[v] = (g[v] + g[u]) % x;
            if (!(--in[v])) q.push(v);
        }
    }

    int k = 0;
    long long tot = 0;
    for (int i = 1; i <= cnt; i++) {
        if (f[i] > k) {
            k = f[i];
            tot = g[i];
        } else if (f[i] == k) tot = (tot + g[i]) % x;
    }
    printf("%d\n%lld\n", k, tot);

    return 0;
}