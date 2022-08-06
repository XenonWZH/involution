#include <cstdio>
#include <algorithm>

const int MAXN = 1e5;

int main() {
    int t;

    scanf("%d", &t);

    while (t--) {
        int n;
        static long long a[MAXN + 1];

        scanf("%d", &n);

        long long ans = 0;
        for (int i = 1; i <= n; i++) {
            scanf("%lld", &a[i]);
            ans = std::max(ans, a[i]);
        }

        long long now = 0;
        for (int i = 1; i <= n; i++) {
            if (a[i] > a[i - 1]) {
                now += a[i] - a[i - 1];
            }
        }

        if (now > ans) puts("NO");
        else puts("YES");
    }

    return 0;
}