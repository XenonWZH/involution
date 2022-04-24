#include <cstdio>
#include <cstring>
#include <iostream>
#include <vector>
#include <stack>
#include <queue>

const int MAXN = 10000;

int n, m, a[MAXN + 1], ac[MAXN + 1];
std::vector<int> e[MAXN + 1];
int dfn[MAXN + 1], low[MAXN + 1], num = 0, cnt = 0;
std::stack<int> sta;
int ins[MAXN + 1], c[MAXN + 1];
std::vector<int> scc[MAXN + 1];
std::vector<int> ec[MAXN + 1], ecRev[MAXN + 1];
int f[MAXN + 1];

void tarjan(int x) {
    dfn[x] = low[x] = ++num;
    sta.push(x);
    ins[x] = 1;
    for (int each : e[x]) {
        if (!dfn[each]) {
            tarjan(each);
            low[x] = std::min(low[x], low[each]);
        } else if (ins[each]) {
            low[x] = std::min(low[x], dfn[each]);
        }
    }
    if (dfn[x] == low[x]) {
        cnt++;
        int y;
        do {
            y = sta.top();
            sta.pop();
            ins[y] = 0;
            c[y] = cnt, scc[cnt].push_back(y);
        } while (x != y);
    }
}

int topo(){
    int ans = 0;
    std::queue<int> q;
    memset(f, 0, sizeof(f));
    for (int i = 1; i <= cnt; i++) {
        if (ecRev[i].size() == 0) {
            q.push(i);
            f[i] = ac[i];
            ans = std::max(ans, f[i]);
        }
    }

    while (!q.empty()) {
        for (int each : ec[q.front()]) {
            q.push(each);
            f[each] = std::max(f[each], f[q.front()] + ac[each]);
            ans = std::max(ans, f[each]);
        }
        q.pop();
    }

    return ans;
}

int main() {
    std::cin >> n >> m;
    for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
    for (int i = 1, a, b; i <= m; i++) {
        scanf("%d%d", &a, &b);
        e[a].push_back(b);
    }

    memset(dfn, 0, sizeof(dfn));
    for (int i = 1; i <= n; i++) {
        if(!dfn[i]) tarjan(i);
    }

    for (int i = 1; i <= n; i++) {
        for (int each : e[i]) {
            if (c[i] == c[each]) continue;
            ec[c[i]].push_back(c[each]);
            ecRev[c[each]].push_back(c[i]);
        }
    }

    memset(ac, 0, sizeof(ac));
    for (int i = 1; i <= cnt; i++) {
        for (int each : scc[i]) {
            ac[i] += a[each];
        }
    }

    std::cout << topo() << std::endl;

    return 0;
}