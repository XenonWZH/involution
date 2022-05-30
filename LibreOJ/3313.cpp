#include <cstdio>
#include <algorithm>

const int MAXN = 100000;

int main() {
    int t;

    scanf("%d", &t);

    while (t--) {
        int n;
        static long long a[MAXN + 2];

        scanf("%d", &n);
        for (int i = 1; i <= n; i++) {
            scanf("%lld", &a[i]);
        }

        long long ans = 0, line = 0, dance1 = 0, dance2 = 0;

        for (int i = 1; i <= n; i++) {
            long long after = 0, tmp = line + dance1 - a[i + 1];

            if (tmp > 0) {
                if (tmp > line) dance1 = dance1 + line - tmp, tmp = line;
                if (tmp > dance1) line = line + dance1 - tmp, tmp = dance1;

                line -= tmp, dance1 -= tmp, a[i + 1] -= tmp, after = tmp;
            }

            a[i + 1] -= line + dance1;
            ans += a[i];

            long long before = std::min(a[i], a[i + 1]);
            line += before;
            a[i] -= before, a[i + 1] -= before;

            dance2 += a[i];
            a[i + 1] += after, ans -= after;

            std::swap(dance1, dance2);
        }

        printf("%lld\n", ans);
    }

    return 0;
}