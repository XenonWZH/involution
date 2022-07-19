#include <cstdio>
#include <cstring>
#include <algorithm>

const int MAXN = 1e5;

int main() {
    int t;

    scanf("%d", &t);

    while (t--) {
        int n;
        static int c[MAXN + 1];

        scanf("%d", &n);
        for (int i = 1; i <= n; i++) {
            scanf("%d", &c[i]);
        }

        static int pos[MAXN + 1], cnt[MAXN + 1], ans[MAXN + 1];
        memset(pos, 0, sizeof(pos));
        memset(cnt, 0, sizeof(cnt));
        memset(ans, 0, sizeof(ans));

        for (int i = 1; i <= n; i++) {
            if (pos[c[i]] != 0) {
                if ((i - pos[c[i]]) % 2) {
                    cnt[c[i]]++;
                    ans[c[i]] = std::max(ans[c[i]], cnt[c[i]]);
                }
            } else cnt[c[i]] = ans[c[i]] = 1;

            pos[c[i]] = i;
        }

        for (int i = 1; i <= n; i++) {
            printf("%d ", ans[i]);
        }
        putchar('\n');
    }

    return 0;
}