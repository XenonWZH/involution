#include <cstdio>
#include <cmath>
#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    int n;

    while (scanf("%d", &n) != EOF) {
        std::vector<long long> a(n);
        unsigned long long s = 0;

        for (int i = 0; i < n; i++) {
            scanf("%lld", &a[i]);
            s += a[i];
        }

        long long average = s / n;
        std::vector<long long> c(n);
        c[0] = a[0] - average;
        for (int i = 1; i < n; i++) c[i] = c[i - 1] + a[i] - average;

        std::sort(c.begin(), c.end());
        long long mid = c[n / 2];
        long long ans = 0;
        for (int i = 0; i < n; i++) ans += std::abs(mid - c[i]);
        printf("%lld\n", ans);
    }

    return 0;
}