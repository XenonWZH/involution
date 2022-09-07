#include <cstdio>
#include <iostream>
#include <algorithm>
#include <stack>
#include <vector>

const int MAXN = 1e5;

struct UnionFindSet {
    int fa[2 * MAXN + 1];

    void init(int n) {
        for (int i = 1; i <= n; i++) fa[i] = i;
    }

    int find(int x) {
        return x == fa[x] ? x : fa[x] = find(fa[x]);
    }

    void merge(int x, int y) {
        fa[find(x)] = find(y); 
    }
} ufs;

int main() {
    int t;

    scanf("%d", &t);

    while (t--) {
        int n;
        static char s[2 * MAXN + 2];

        scanf("%d", &n);
        scanf("%s", s + 1);

        static std::stack<int> sta;
        static std::vector< std::pair<int, int> > bracket;
        while (!sta.empty()) sta.pop();
        bracket.clear();
        for (int i = 1; i <= 2 * n; i++) {
            if (s[i] == '(') sta.push(i);
            else if(s[i] == ')') {
                bracket.push_back( std::make_pair(sta.top(), i) );
                sta.pop();
            }
        }

        ufs.init(2 * n);

        std::sort(bracket.begin(), bracket.end());
        static std::stack<int> right;
        while (!right.empty()) right.pop();
        for (auto each : bracket) {
            while (!right.empty() && right.top() < each.first - 1) right.pop();
            if (!right.empty() && right.top() == each.first - 1) {
                ufs.merge(right.top(), each.first);
                right.pop();
            }
            ufs.merge(each.first, each.second);
            right.push(each.second);
        }

        static bool mark[2 * MAXN + 1];
        for (int i = 1; i <= 2 * n; i++) mark[i] = false;
        for (int i = 1; i <= 2 * n; i++) mark[ufs.find(i)] = true;

        int ans = 0;
        for (int i = 1; i <= 2 * n; i++) ans += mark[i];
        printf("%d\n", ans);
    }

    return 0;
}