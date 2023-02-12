#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#include <stack>
#include <map>

const int MAXN = 1000;

int n, m;
std::vector<int> G[MAXN + 1];
bool cut[MAXN + 1];

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
    int flag = 0;
    for (int v : G[u]) {
        if (!dfn[v]) {
            tarjan(v);
            low[u] = std::min(low[u], low[v]);
            if (low[v] >= dfn[u]) {
                flag++;
                if (u != root || flag > 1) cut[u] = true;
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

void init() {
    n = ts = cnt = 0;
    for (int i = 0; i < MAXN; i++) G[i].clear();
    memset(cut, false, sizeof(cut));
    memset(dfn, 0, sizeof(dfn));
    memset(low, 0, sizeof(low));
    memset(dcc, 0, sizeof(dcc));
}

int main() {
    int t = 0;

    while (scanf("%d", &m) != EOF && m) {
        init();

        std::map<int, int> mp;
        mp.clear();
        for (int i = 1; i <= m; i++) {
            int u, v;
            scanf("%d %d", &u, &v);
            if (!mp[u]) mp[u] = ++n;
            if (!mp[v]) mp[v] = ++n;
            G[mp[u]].push_back(mp[v]);
            G[mp[v]].push_back(mp[u]);
        }

        for (int i = 1; i <= n; i++) {
            if (!dfn[i]) {
                root = i;
                tarjan(i);
            }
        }

        unsigned long long ans = 0, cases = 1;
        for (int i = 1; i <= cnt; i++) {
            int cnts = 0;
            for (int u : dcc[i]) if (cut[u]) cnts++;
            if (cnts == 0) ans += 2, cases *= 1ull * dcc[i].size() * (dcc[i].size() - 1) / 2;
            else if (cnts == 1) ans++, cases *= dcc[i].size() - 1;
        }
        printf("Case %d: %llu %llu\n", ++t, ans, cases);
    }

    return 0;
}