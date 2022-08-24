#include <cstdio>
#include <algorithm>

const int MAXN = 2e5;

int main() {
    int t;

    scanf("%d", &t);

    while (t--) {
        int n, x;
        static int a[MAXN + 1];

        scanf("%d %d", &n, &x);
        for (int i = 1; i <= n; i++) scanf("%d", &a[i]);

        int ans = 0;
        int l = 1, r = 1, mina = a[1], maxa = a[1];
        while (r < n) {
            r++;
            mina = std::min(mina, a[r]);
            maxa = std::max(maxa, a[r]);
            if (maxa - mina >= 2 * x + 1) ans++, l = r, mina = maxa = a[l];
        }

        printf("%d\n", ans);
    }

    return 0;
}