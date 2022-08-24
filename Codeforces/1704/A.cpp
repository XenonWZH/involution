#include <cstdio>
#include <iostream>

const int MAXN = 50;

int main() {
    int t;

    scanf("%d", &t);
    while (t--) {
        int n, m;
        static char a[MAXN + 1], b[MAXN + 1];

        scanf("%d %d", &n, &m);
        scanf("%s", a);
        scanf("%s", b);

        bool ans = true;
        for (int i = 1; i < m; i++) {
            if (a[i + n - m] != b[i]) {
                ans = false;
            }
        }

        if (ans == 0) {
            puts("NO");
            continue;
        }

        ans = false;
        for (int i = 0; i <= n - m; i++) {
            if (b[0] == a[i]) {
                ans = true;
            }
        }

        if (ans) puts("YES");
        else puts("NO");
    }

    return 0;
}
