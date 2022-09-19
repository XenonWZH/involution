#include <cstdio>
#include <iostream>

const int MAXN = 1e5;

int main() {
    int t;

    scanf("%d", &t);

    while (t--) {
        int n;
        static int a[MAXN + 1];

        scanf("%d", &n);
        for (int i = 1; i <= n; i++) scanf("%d", &a[i]);

        int pos = n;
        while (pos >= 1 && a[pos] % 2 != a[1] % 2) pos--;

        int ans = 0;
        for (int i = pos - 1; i >= 1; i--) {
            if (a[i] % 2 == a[pos] % 2) {
                ans++;
            }
        }
        for (int i = 2; i <= n; i++) {
            if (a[i] % 2 != a[pos] % 2) {
                ans++;
            }
        }

        printf("%d\n", ans);
        for (int i = pos - 1; i >= 1; i--) {
            if (a[i] % 2 == a[pos] % 2) {
                printf("%d %d\n", i, pos);
            }
        }
        for (int i = 2; i <= n; i++) {
            if (a[i] % 2 != a[pos] % 2) {
                printf("%d %d\n", 1, i);
            }
        }
    }

    return 0;
}