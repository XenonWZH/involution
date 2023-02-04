#include <bits/stdc++.h>

namespace XenonWZH {
    const int MAXN = 50000;
    const int MOD = 10007;

    int n, m;
    int a[MAXN + 1], s[MAXN + 1];

    bool check(int limit) {
    int k = m, len = 0;
        for (int i = 1; i <= n; i++) {
            if (len + a[i] > limit) {
                k--;
                len = a[i];
            } else len += a[i];
        }
        return k >= 1;
    }

    int main() {
        scanf("%d %d", &n, &m);
        m++;

        int max = 0;
        for (int i = 1; i <= n; i++) {
            scanf("%d", &a[i]);
            max = std::max(max, a[i]);
            s[i] = s[i - 1] + a[i];
        }

        int l = max, r = s[n];
        while (l < r) {
            int mid = (l + r) / 2;
            if (check(mid)) r = mid;
            else l = mid + 1;
        }

        printf("%d ", l);

        int ans = 0;
        static int f[MAXN + 1][2];
        for (int i = 1; i <= n; i++) f[i][1] = (s[i] <= l ? 1 : 0);
        for (int j = 2; j <= m; j++) {
            for (int i = 1; i <= n; i++) f[i][(j - 1) & 1] = (f[i][(j - 1) & 1] + f[i - 1][(j - 1) & 1]) % MOD;
            for (int i = 1, k = j; i <= n; i++) {
                f[i][j & 1] = 0;
                while (k <= i && s[i] - s[k - 1] > l) k++;
                if (k <= i && s[i] - s[k - 1] <= l) f[i][j & 1] = (f[i][j & 1] + f[i - 1][(j - 1) & 1] - f[k - 2][(j - 1) & 1] + MOD) % MOD;
            }
            ans = (ans + f[n][j & 1]) % MOD;
        }

        printf("%d\n", ans);

        return 0;
    }
};

int main() {
    return XenonWZH::main();
}