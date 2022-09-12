#include <cstdio>
#include <functional>
#include <iostream>
#include <algorithm>

const int MAXN = 1e5;

int main() {
    int t;

    scanf("%d", &t);

    while (t--) {
        int n;
        static int x[MAXN + 1], y[MAXN + 1];

        scanf("%d", &n);

        long long cnt = 0;
        for (int i = 1; i <= n; i++) scanf("%d", &x[i]), cnt -= x[i];
        for (int i = 1; i <= n; i++) scanf("%d", &y[i]), cnt += y[i];

        static int a[MAXN + 1];
        for (int i = 1; i <= n; i++) a[i] = y[i] - x[i];
        std::sort(a + 1, a + n + 1);

        int ans = 0, l = 1, r = n;
        while (l < r) {
            if (a[l] + a[r] < 0) l++;
            else l++, r--, ans++;
        }

        printf("%d\n", ans);
    }

    return 0;
}