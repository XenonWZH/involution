#include <cstdio>
#include <algorithm>

const int MAXN = 2e5;

int main() {
    int t;

    scanf("%d", &t);

    while (t--) {
        int n;
        scanf("%d", &n);

        static int a[MAXN + 1];

        if (n % 4 == 0) {
            for (int i = 1; i <= n; i++) a[i] = i + 1;
        } else if (n % 4 == 1) {
            a[n] = 0;
            for (int i = 1; i <= n - 1; i++) a[i] = i + 1;
        } else if (n % 4 == 2) {
            for (int i = 1; i <= n; i++) a[i] = i + 1;
            a[1] |= (1 << 30);
            a[3] |= (1 << 30) | 1;
        } else if (n % 4 == 3) {
            a[n] = 0;
            for (int i = 1; i <= n - 1; i++) a[i] = i + 1;
            a[1] |= (1 << 30);
            a[3] |= (1 << 30) | 1;
        }

        for (int i = 1; i <= n; i++) printf("%d ", a[i]);
        putchar('\n');
    }

    return 0;
}