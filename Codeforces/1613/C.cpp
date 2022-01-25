#include <cstdio>
#include <algorithm>

typedef unsigned long long ull;
const int MAXN = 100;

int main() {

    int t;

    scanf("%d", &t);

    while (t--) {
        int n;
        ull h;
        static ull a[MAXN];

        scanf("%d%llu", &n, &h);
        for (int i = 0; i < n; i++) {
            scanf("%llu", &a[i]);
        }

        std::sort(a, a + n);

        ull l = 0, r = 1e18 + 1;
        while (l < r) {
            ull mid = (l + r) >> 1;

            ull sum = 0;
            for (int i = 0; i < n - 1; i++) {
                if (a[i + 1] - a[i] >= mid) sum += mid;
                else sum += a[i + 1] - a[i];
            }
            sum += mid;

            if (sum >= h) r = mid;
            else l = mid + 1;
        }

        printf("%llu\n", l);
    }

    return 0;
}