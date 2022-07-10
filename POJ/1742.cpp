#include <cstdio>
#include <cstring>

const int MAXN = 100, MAXM = 100000;

int main() {
    int n, m;
    static int a[MAXN], c[MAXN];

    while (scanf("%d %d", &n, &m) != EOF) {
        if (n == 0 && m == 0) break;

        for (int i = 0; i < n; i++) scanf("%d", &a[i]);
        for (int i = 0; i < n; i++) scanf("%d", &c[i]);

        static bool f[MAXM + 1];
        static int used[MAXM + 1];
        memset(f, false, sizeof(f));
        f[0] = true;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j <= m; j++) used[j] = 0;
            for (int j = a[i]; j <= m; j++) {
                if (!f[j] && f[j - a[i]] && used[j - a[i]] < c[i]) {
                    f[j] = true, used[j] = used[j - a[i]] + 1;
                }
            }
        }

        int ans = 0;
        for (int i = 1; i <= m; i++) ans += f[i];

        printf("%d\n", ans);
    }

    return 0;
}