#include <cstdio>
#include <algorithm>

const int MAXK = 16;
const int MAXN = 100000;

int main() {
    int k, n;
    scanf("%d %d", &k, &n);

    static long long money[MAXK];
    for (int i = 0; i < k; i++) scanf("%lld", &money[i]);

    static long long s[MAXN + 1];
    for (int i = 1; i <= n; i++) {
        scanf("%lld", &s[i]);
        s[i] += s[i - 1];
    }

    static int f[1 << MAXK];
    for (int i = 1; i < (1 << k); i++) {
        for (int j = 0; j < k; j++) {
            if ((i >> j) & 1) {
                int x = i ^ (1 << j);
                if (f[x] == n) {
                    f[i] = n;
                    continue;
                }

                int l = f[x] + 1, r = n;
                while (l < r) {
                    int mid = (l + r + 1) / 2;
                    if (s[mid] - s[f[x]] <= money[j]) l = mid;
                    else r = mid - 1;
                }

                f[i] = std::max(f[i], l);
            }
        }
    }

    long long ans = -1;
    for (int i = 1; i < (1 << k); i++) {
        if (f[i] == n) {
            long long res = 0;
            for (int j = 0; j < k; j++) if (!((i >> j) & 1)) res += money[j];
            ans = std::max(ans, res);
        }
    }
    printf("%lld\n", ans);

    return 0;
}