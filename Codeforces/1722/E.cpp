#include <cstdio>
#include <cstring>
#include <algorithm>

const int MAXN = 1e5;
const int MAXH = 1000;

int main() {
    int t;

    scanf("%d", &t);

    while (t--) {
        int n, q;

        scanf("%d %d", &n, &q);

        static long long a[MAXH + 1][MAXH + 1];
        static long long s[MAXH + 1][MAXH + 1];
        memset(a, 0, sizeof(a));
        memset(s, 0, sizeof(s));
        int mh = 0, mw = 0;

        for (int i = 1; i <= n; i++) {
            int h, w;
            scanf("%d %d", &h, &w);
            mh = std::max(mh, h), mw = std::max(mw, w);
            a[h][w] += (long long)h * w;
        }

        static int hs[MAXN + 1], hb[MAXN + 1], ws[MAXN + 1], wb[MAXN + 1];
        for (int i = 1; i <= q; i++) {
            scanf("%d %d %d %d", &hs[i], &ws[i], &hb[i], &wb[i]);
            mh = std::max(mh, hb[i]), mw = std::max(mw, wb[i]);
        }

        for (int i = 1; i <= mh; i++) {
            for (int j = 1; j <= mw; j++) {
                s[i][j] = s[i][j - 1] + s[i - 1][j] - s[i - 1][j - 1] + a[i][j];
            }
        }

        for (int i = 1; i <= q; i++) {
            printf("%lld\n", std::max(0ll, s[hb[i] - 1][wb[i] - 1] - s[hb[i] - 1][ws[i]] - s[hs[i]][wb[i] - 1] + s[hs[i]][ws[i]]));
        }
    }

    return 0;
}