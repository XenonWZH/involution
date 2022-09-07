#include <cstdio>
#include <iostream>

const int MAXN = 2000;

int main() {
    int t;

    scanf("%d", &t);

    while (t--) {
        int n;
        static int a[MAXN + 1];

        scanf("%d", &n);
        for (int i = 1; i <= n; i++) scanf("%d", &a[i]);

        int ans = a[n] - a[1];
        for (int i = 1; i <= n - 1; i++) ans = std::max(ans, a[i] - a[i + 1]);
        for (int i = 2; i <= n; i++) ans = std::max(ans, a[i] - a[1]);
        for (int i = 1; i <= n - 1; i++) ans = std::max(ans, a[n] - a[i]);

        printf("%d\n", ans);
    }

    return 0;
}