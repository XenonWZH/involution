#include <cstdio>
#include <cstring>
#include <algorithm>

const int MAXN = 100, MAXA = 25000;

int main() {
#ifndef DBG
    freopen("money.in", "r", stdin);
    freopen("money.out", "w", stdout);
#endif

    int t;

    scanf("%d", &t);

    while (t--) {
        int n;
        static int a[MAXN];

        scanf("%d", &n);
        for (int i = 0; i < n; i++) {
            scanf("%d", &a[i]);
        }

        static bool f[MAXA + 1];
        memset(f, false, sizeof(f));
        f[0] = true;

        std::sort(a, a + n);

        int ans = n;
        for (int i = 0; i < n; i++) {
            if (f[a[i]]) {
                ans--;
                continue;
            }
            f[a[i]] = true;
            for (int j = a[i]; j <= a[n - 1]; j++) {
                f[j] |= f[j - a[i]];
            }
        }

        printf("%d\n", ans);
    }

#ifndef DBG
    fclose(stdin);
    fclose(stdout);
#endif

    return 0;
}