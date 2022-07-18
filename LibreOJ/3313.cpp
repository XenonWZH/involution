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

        long long line = 0, dance1 = 0, dance2 = 0, ans = 0, nxt = 0;

        for (int i = 1; i <= n; i++) {
            if (a[i + 1] < dance1 + line) {
                int delta = dance1 + line - a[i + 1];
                if (line > a[i + 1]) {
                    line = a[i + 1];
                    delta = dance1;
                }
                if (dance1 > a[i + 1]) {
                    dance1 = a[i + 1];
                    delta = line;
                }
                line -= delta;
                dance1 -= delta;
                nxt = delta;
                a[i + 1] -= nxt;
            }

            a[i + 1] -= line + dance1;
            ans += a[i];

            if (a[i] <= a[i + 1]) {
                line += a[i];
                a[i + 1] -= a[i];
                a[i] = 0;
            } else {
                line += a[i + 1];
                dance2 += a[i] - a[i + 1];
                a[i] = a[i + 1] = 0;
            }

            a[i + 1] += nxt;
            ans -= nxt;
            nxt = 0;

            std::swap(dance1, dance2);
        }

        printf("%lld\n", ans);
    }

    return 0;
}