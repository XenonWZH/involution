#include <cstdio>
#include <algorithm>

const int MAXN = 1e5;

int main() {
    int t;

    scanf("%d", &t);

    while (t--) {
        int n;
        static long long h[MAXN + 1];

        scanf("%d", &n);
        for (int i = 1; i <= n; i++) {
            scanf("%lld", &h[i]);
        }

        if (n == 1 || n == 2) {
            puts("0");
            continue;
        }

        long long ans = 0;

        if (n % 2) {
            for (int i = 2; i <= n - 1; i += 2) {
                if (std::max(h[i - 1], h[i + 1]) >= h[i]) {
                    ans += std::max(h[i - 1], h[i + 1]) + 1 - h[i];
                }
            }
        } else {
            for (int i = 2; i <= n - 2; i += 2) {
                if (std::max(h[i - 1], h[i + 1]) >= h[i]) {
                    ans += std::max(h[i - 1], h[i + 1]) + 1 - h[i];
                }
            }
            long long ansTmp = ans;
            for (int i = n - 1; i >= 3; i -= 2) {
                if (std::max(h[i - 2], h[i]) >= h[i - 1]) {
                    ansTmp -= std::max(h[i - 2], h[i]) + 1 - h[i - 1];
                }
                if (std::max(h[i - 1], h[i + 1]) >= h[i]) {
                    ansTmp += std::max(h[i - 1], h[i + 1]) + 1 - h[i];
                }
                ans = std::min(ans, ansTmp);
            }
        }

        printf("%lld\n", ans);
    }

    return 0;
}