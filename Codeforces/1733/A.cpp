#include <cstdio>
#include <cstring>
#include <iostream>

const int MAXN = 100;

int main() {
    int t;

    scanf("%d", &t);

    while (t--) {
        int n, k;
        static int a[MAXN + 1];

        scanf("%d %d", &n, &k);
        for (int i = 1; i <= n; i++) scanf("%d", &a[i]);

        static int mod[MAXN + 1];
        memset(mod, 0, sizeof(mod));
        for (int i = 1; i <= n; i++) mod[i % k] = std::max(mod[i % k], a[i]);

        long long ans = 0;
        for (int i = 0; i < k; i++) ans += mod[i];

        printf("%lld\n", ans);
    }

    return 0;
}