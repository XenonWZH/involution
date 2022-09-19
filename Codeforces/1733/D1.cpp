#include <cstdio>
#include <cstring>
#include <iostream>
#include <vector>

const int MAXN = 5000;

int main() {
    int t;

    scanf("%d", &t);

    while (t--) {
        int n, x, y;
        static char a[MAXN + 2], b[MAXN + 2];

        scanf("%d %d %d", &n, &x, &y);
        scanf("%s", a + 1);
        scanf("%s", b + 1);

        int cnt = 0;
        bool flag = true;
        for (int i = 1; i <= n; i++) {
            if (a[i] != b[i]) {
                cnt++;
                if (i <= n - 1 && a[i + 1] != b[i + 1]) flag = false;
            }
        }

        if (cnt % 2) {
            puts("-1");
            continue;
        }

        if (cnt == 0) puts("0");
        else if (cnt > 2 || flag) printf("%lld\n", 1ll * cnt / 2 * y);
        else {
            if (2 * y > x) printf("%d\n", x);
            else printf("%d\n", 2 * y);
        }
    }

    return 0;
}