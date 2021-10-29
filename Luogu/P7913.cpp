// P7913 [CSP-S 2021] 廊桥分配
// WzhDnwzWzh

#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <queue>

const int MAXN = 100007;

int read() {
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

int main() {
    int n, m1, m2;

    std::cin >> n >> m1 >> m2;

    static std::pair<int, int> ch[MAXN];
    static std::pair<int, int> ab[MAXN];

    for (int i = 0, x, y; i < m1; i++) {
        x = read();
        y = read();
        ch[i] = std::make_pair(x, y);
    }
    for (int i = 0, x, y; i < m2; i++) {
        x = read();
        y = read();
        ab[i] = std::make_pair(x, y);
    }

    std::sort(ch, ch + m1);
    std::sort(ab, ab + m2);

    static std::priority_queue< int, std::vector<int>, std::greater<int> > chN;
    static std::priority_queue< int, std::vector<int>, std::greater<int> > abN;
    static std::priority_queue< std::pair<int, int>, std::vector< std::pair<int, int> >, std::greater< std::pair<int, int> > > chU;
    static std::priority_queue< std::pair<int, int>, std::vector< std::pair<int, int> >, std::greater< std::pair<int, int> > > abU;
    static int chH[MAXN];
    static int abH[MAXN];

    memset(chH, 0, sizeof(chH));
    memset(abH, 0, sizeof(abH));
    chH[0] = abH[0] = 1;
    for (int i = 1; i <= n; i++) {
        chN.push(i);
        abN.push(i);
    }
    chU.push( std::make_pair(ch[0].second, 0) );
    abU.push( std::make_pair(ab[0].second, 0) );

    for (int i = 1; i < m1; i++) {
        while (!chU.empty() && chU.top().first <= ch[i].first) {
            chN.push( chU.top().second );
            chU.pop();
        }
        if (!chN.empty()) {
            chH[chN.top()]++;
            chU.push( std::make_pair( ch[i].second, chN.top() ) );
            chN.pop();
        }
    }
    for (int i = 1; i < m2; i++) {
        while (!abU.empty() && abU.top().first <= ab[i].first) {
            abN.push( abU.top().second );
            abU.pop();
        }
        if (!abN.empty()) {
            abH[abN.top()]++;
            abU.push( std::make_pair( ab[i].second, abN.top() ) );
            abN.pop();
        }
    }

    int chS[MAXN], abS[MAXN];
    chS[0] = abS[0] = 0;

    for (int i = 1; i <= n; i++) {
        chS[i] = chS[i - 1] + chH[i - 1];
        abS[i] = abS[i - 1] + abH[i - 1];
    }

    int ans = 0;
    for (int i = 0; i <= n; i++) {
        if (chS[i] + abS[n - i] > ans) {
            ans = chS[i] + abS[n - i];
        }
    }

    std::cout << ans << std::endl;

    return 0;
}