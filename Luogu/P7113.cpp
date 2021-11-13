// P7113 [NOIP2020] 排水系统
// WzhDnwzWzh

#include <cstdio>
#include <cstring>
#include <iostream>
#include <vector>

#define LOCAL

typedef __uint128_t li;

const int MAXN = 100000;

int n, m;
std::vector<int> graph[MAXN + 1];
int node[MAXN + 1];
bool get[MAXN + 1];

std::pair<li, li> ans[MAXN + 1];

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

void write(li x) {
    if (x > 0) {
        write(x / 10);
        putchar(x % 10 + '0');
    }
}

li gcd(li a, li b) {
    return b == 0 ? a : gcd(b, a % b);
}

li lcm(li a, li b) {
    return a * b / gcd(a, b);
}

void dfs(int num, int step, int re) {
    if (ans[num].first == 0 && ans[num].second == 0) {
        ans[num].first = re;
        ans[num].second = step;
    } else {
        li x = lcm(step, ans[num].second);
        li y = re * x / step + ans[num].first * x / ans[num].second;
        li z = gcd(x, y);
        ans[num].first = y / z;
        ans[num].second = x / z;
    }

    if (get[num]) return;

    for (int each : graph[num]) {
        dfs(each, step * node[num], ans[num].first);
    }
    ans[num].first = ans[num].second = 0;
}

int main() {
#ifndef LOCAL
    freopen("water.in", "r", stdin);
    freopen("water.out", "w", stdout);
#endif

    static std::vector<int> getV;

    memset(get, false, sizeof(get));
    memset(ans, 0, sizeof(ans));

    std::cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        node[i] = read();
        if (node[i] == 0) {
            get[i] = true;
            getV.push_back(i);
        }
        for (int j = 0, x; j < node[i]; j++) {
            x = read();
            graph[i].push_back(x);
        }
    }

    for (int i = 1; i <= m; i++) {
        dfs(i, 1, 1);
    }

    for (int each : getV) {
        write(ans[each].first);
        putchar(' ');
        write(ans[each].second);
        puts("");
    }

#ifndef LOCAL
    fclose(stdin);
    fclose(stdout);
#endif

    return 0;
}
