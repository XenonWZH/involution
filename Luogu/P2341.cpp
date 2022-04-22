#include <cstdio>
#include <cstring>
#include <iostream>
#include <vector>
#include <stack>

const int MAXN = 10000;

int n, m;
std::vector<int> e[MAXN + 1];
int dfn[MAXN + 1], low[MAXN + 1], num = 0, cnt = 0;
std::stack<int> sta;
int ins[MAXN + 1], c[MAXN + 1];
std::vector<int> scc[MAXN + 1];
std::vector<int> ec[MAXN + 1];

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

int main() {
    std::cin >> n >> m;

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
        }
    }

    int counts = 0, pos = 0;
    for (int i = 1; i <= cnt; i++) {
        if (ec[i].size() == 0) {
            counts++;
            pos = i;
        }
    }

    if (counts == 1) std::cout << scc[pos].size() << std::endl;
    else std::cout << "0" << std::endl;

    return 0;
}