#include <cstdio>
#include <cstring>
#include <iostream>
#include <vector>
#include <stack>

const int MAXN = 100;

int n;
std::vector<int> e[MAXN + 1];
int dfn[MAXN + 1], low[MAXN + 1], num = 0, cnt = 0;
std::stack<int> sta;
int ins[MAXN + 1], c[MAXN + 1];
std::vector<int> scc[MAXN + 1];
std::vector<int> ec[MAXN + 1], ecRev[MAXN + 1];

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
    std::cin >> n;

    for (int i = 1, x; i <= n; i++) {
        while (scanf("%d", &x) != EOF) {
            if (x == 0) break;
            e[i].push_back(x);
        }
    }

    memset(dfn, 0, sizeof(dfn));
    for (int i = 1; i <= n; i++) {
        if(!dfn[i]) {
            tarjan(i);
        }
    }

    for (int i = 1; i <= n; i++) {
        for (int each : e[i]) {
            if (c[i] == c[each]) continue;
            ec[c[i]].push_back(c[each]);
            ecRev[c[each]].push_back(c[i]);
        }
    }

    int count1 = 0, count2 = 0;
    for (int i = 1; i <= cnt; i++) {
        if (ecRev[i].size() == 0) count1++;
        if (ec[i].size() == 0) count2++;
    }
    count2 = std::max(count1, count2);
    if (cnt == 1) count1 = 1, count2 = 0;

    std::cout << count1 << std::endl <<  count2 << std::endl;

    return 0;
}