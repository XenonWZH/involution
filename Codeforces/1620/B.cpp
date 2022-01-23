#include <cstdio>

int main() {
    int t;

    scanf("%d", &t);

    while (t--) {
        long long w, h;
        long long kx1, kx2, ky1, ky2;
        long long minKx1, maxKx1, minKx2, maxKx2, minKy1, maxKy1, minKy2, maxKy2;
        minKx1 = minKx2 = minKy1 = minKy2 = 0x7f7f7f;
        maxKx1 = maxKx2 = maxKy1 = maxKy2 = -1;

        scanf("%lld%lld", &w, &h);

        scanf("%lld", &kx1);
        for (long long i = 0, x; i < kx1; i++) {
            scanf("%lld", &x);
            if (x < minKx1) minKx1 = x;
            if (x > maxKx1) maxKx1 = x;
        }

        scanf("%lld", &kx2);
        for (long long i = 0, x; i < kx2; i++) {
            scanf("%lld", &x);
            if (x < minKx2) minKx2 = x;
            if (x > maxKx2) maxKx2 = x;
        }

        scanf("%lld", &ky1);
        for (long long i = 0, x; i < ky1; i++) {
            scanf("%lld", &x);
            if (x < minKy1) minKy1 = x;
            if (x > maxKy1) maxKy1 = x;
        }

        scanf("%lld", &ky2);
        for (long long i = 0, x; i < ky2; i++) {
            scanf("%lld", &x);
            if (x < minKy2) minKy2 = x;
            if (x > maxKy2) maxKy2 = x;
        }

        long long ans = -1;
        if ((maxKx1 - minKx1) * h > ans) ans = (maxKx1 - minKx1) * h;
        if ((maxKx2 - minKx2) * h > ans) ans = (maxKx2 - minKx2) * h;
        if ((maxKy1 - minKy1) * w > ans) ans = (maxKy1 - minKy1) * w;
        if ((maxKy2 - minKy2) * w > ans) ans = (maxKy2 - minKy2) * w;

        printf("%lld\n", ans);
    }

    return 0;
}