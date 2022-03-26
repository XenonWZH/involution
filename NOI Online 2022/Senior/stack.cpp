#include <cstdio>
#include <iostream>
#include <stack>

const int MAXN = 500000;

int main() {
    freopen("stack.in", "r", stdin);
    freopen("stack.out", "w", stdout);

    int n, q;
    static int a[MAXN + 1], b[MAXN + 1];

    std::cin >> n >> q;

    for (int i = 1; i <= n; i++) {
        scanf("%d", &a[i]);
    }

    static std::stack<int> sta;
    static int sucess[MAXN + 1];
    for (int i = 1; i <= n; i++) {
        scanf("%d", &b[i]);
        while (!sta.empty() && !(a[i] != a[sta.top()] && b[i] < b[sta.top()])) sta.pop();
        if (sta.empty()) sucess[i] = 0;
        else sucess[i] = sta.top();
        sta.push(i);
    }

    for (int i = 1; i <= q; i++) {
        int l, r;
        scanf("%d%d", &l, &r);

        int cnt = 1, minn = l;
        for (int j = l + 1; j <= r; j++) {
            if (sucess[j] < minn) {
                cnt++;
                minn = j;
            }
        }

        printf("%d\n", cnt);
    }

    fclose(stdin);
    fclose(stdout);
    return 0;
}