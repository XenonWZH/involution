#include <cstdio>
#include <cstring>

const int MAXN = 100;

int main() {
    int t;

    scanf("%d", &t);

    while (t--) {
        int n, a, b;

        scanf("%d%d%d", &n, &a, &b);

        if (!((a + n / 2 - 1 > n || b - n / 2 + 1 < 1) ||
              ((a + n / 2 - 1 == n && b == n) || (a == 1 && b - n / 2 + 1 == 1)) ||
              n % 2 != 0)) {
            bool ok = true;
            static bool mark[MAXN + 1];
            static int ans[MAXN + 1];
            memset(mark, true, sizeof(mark));
            mark[a] = mark[b] = false;

            ans[1] = a;
            for (int i = n, cnt = n, cntA = 2; i > n / 2 + 1; i--, cnt--) {
                if (mark[cnt]) {
                    ans[cntA++] = cnt;
                    mark[cnt] = false;
                    if (ans[cntA - 1] < a) ok = false;
                } else i++;
            }
            ans[n / 2 + 1] = b;
            for (int i = n, cnt = n / 2 + 2; i >= 1; i--)
                if (mark[i]) {
                    ans[cnt++] = i;
                    if (ans[cnt - 1] > b) ok = false;
                }

            if (ok) {
                for (int i = 1; i <= n; i++) printf("%d ", ans[i]);
                puts("");
            } else puts("-1");
        } else printf("-1\n");
    }

    return 0;
}