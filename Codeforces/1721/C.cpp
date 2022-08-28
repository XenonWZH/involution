#include <cstdio>
#include <cstring>
#include <algorithm>
#include <queue>

const int MAXN = 2e5;

int main() {
    int t;

    scanf("%d", &t);

    while (t--) {
        int n;
        static int a[MAXN + 1], b[MAXN + 1];

        scanf("%d", &n);
        for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
        for (int i = 1; i <= n; i++) scanf("%d", &b[i]);

        static int p[MAXN + 1];
        for (int i = 1; i <= n; i++) p[i] = std::lower_bound(b + 1, b + n + 1, a[i]) - b;

        for (int i = 1; i <= n; i++) printf("%d ", b[p[i]] - a[i]);
        putchar('\n');

        int pos = n;
        static int ans[MAXN + 1];
        for (int i = n; i >= 1; i--) {
            ans[i] = b[pos] - a[i];
            if (i == p[i]) pos = i - 1;
        }

        for (int i = 1; i <= n; i++) printf("%d ", ans[i]);
        putchar('\n');
    }

    return 0;
}