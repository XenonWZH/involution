#include <cstdio>

const int MAXN = 1e5;

int main() {
    int n, m;
    static int a[MAXN + 1], s[MAXN + 1], t[MAXN + 1];

    scanf("%d %d", &n, &m);
    for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
    for (int i = 1; i <= m; i++) scanf("%d %d", &s[i], &t[i]);

    static long long ans[MAXN + 1], revAns[MAXN + 1];
    for (int i = 1; i <= n; i++) {
        if (a[i] < a[i - 1]) ans[i] = ans[i - 1] + a[i - 1] - a[i];
        else ans[i] = ans[i - 1];
    }
    for (int i = n; i >= 1; i--) {
        if (a[i + 1] > a[i]) revAns[i] = revAns[i + 1] + a[i + 1] - a[i];
        else revAns[i] = revAns[i + 1];
    }

    for (int i = 1; i <= m; i++) {
        if (s[i] < t[i]) printf("%lld\n", ans[t[i]] - ans[s[i]]);
        else printf("%lld\n", revAns[t[i]] - revAns[s[i]]);
    }

    return 0;
}