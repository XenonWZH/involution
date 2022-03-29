#include <cstdio>
#include <iostream>
#include <stack>
#include <vector>

const int MAXN = 500000;

int c[MAXN + 1], n;

inline int lowbit(int x) {
    return x & -x;
}

inline void add(int x, int k) {
    while (x <= n) {
        c[x] = c[x] + k;
        x = x + lowbit(x);
    }
}

inline int getSum(int x) {
    int ans = 0;
    while (x >= 1) {
        ans = ans + c[x];
        x = x - lowbit(x);
    }
    return ans;
}

int main() {
    int q;
    static int a[MAXN + 1], b[MAXN + 1], l[MAXN + 1], r[MAXN + 1];

    std::cin >> n >> q;
    for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
    for (int i = 1; i <= n; i++) scanf("%d", &b[i]);

    static std::stack<int> sta;
    static std::vector<int> v[MAXN + 1];
    for (int i = 1; i <= n; i++) {
        while (!sta.empty() && !(a[i] != a[sta.top()] && b[i] < b[sta.top()])) sta.pop();
        v[sta.empty() ? 0 : sta.top()].push_back(i);
        sta.push(i);
    }

    static std::vector<int> id[MAXN + 1];
    for (int i = 0; i < q; i++) {
        scanf("%d%d", &l[i], &r[i]);
        id[l[i]].push_back(i);
    }

    static int ans[MAXN + 1];
    for (int i = 0; i <= n; i++) {
        for (int j : id[i]) {
            ans[j] = getSum(r[j]) - l[j] + 1;
        }
        for (int j : v[i]) add(j, 1);
    }

    for (int i = 0; i < q; i++) {
        printf("%d\n", ans[i]);
    }

    return 0;
}