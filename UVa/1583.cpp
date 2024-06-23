#include <cstdio>
#include <cstring>
#include <iostream>

const int MAXN = 100000;

int main() {
    static int ori[MAXN + 1];
    for (int i = 1; i <= MAXN; i++) {
        int t = i;
        ori[i] = i;
        while (t > 0) {
            ori[i] += t % 10;
            t /= 10;
        }
    }

    static int ans[MAXN + 1];
    for (int i = 1; i <= MAXN; i++) ans[i] = MAXN + 1;
    for (int i = 1; i <= MAXN; i++) if (ori[i] <= MAXN) ans[ori[i]] = std::min(ans[ori[i]], i);

    int t;

    scanf("%d", &t);

    while (t--) {
        int n;
        scanf("%d", &n);
        printf("%d\n", ans[n] == MAXN + 1 ? 0 : ans[n]);
    }

    return 0;
}