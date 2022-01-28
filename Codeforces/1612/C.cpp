#include <cstdio>

typedef unsigned long long ull;

int main() {
    int t;

    scanf("%d", &t);

    while (t--) {
        ull k, x;

        scanf("%llu%llu", &k, &x);

        ull tra1 = k * (k + 1) / 2, tra2 = k * (k - 1) / 2, tra = tra1 + tra2, ans = 0;

        ans += (x / tra) * (2 * k - 1);
        x -= ans;

        if (x >= tra1) {
            ans += k;
            x -= tra1;
            ull l = 0, r = k - 1;
            while (l < r) {
                ull mid = (l + r) >> 1;
                ull tmp = mid * (2 * k - mid - 1) / 2;
                if (tmp < x) l = mid + 1;
                else r = mid;
            }
            ans += l;
        } else {
            ull l = 0, r = k;
            while (l < r) {
                ull mid = (l + r) >> 1;
                ull tmp = mid * (1 + mid) / 2;
                if (tmp < x) l = mid + 1;
                else r = mid;
            }
            ans += l;
        }

        printf("%llu\n", ans > 2 * k - 1 ? 2 * k - 1 : ans);
    }

    return 0;
}