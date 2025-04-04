#include <bits/stdc++.h>

typedef unsigned long long ull;

int main() {
    int n;
    ull k, t;
    scanf("%d %llu %llu", &n, &k, &t);
    t *= k * k;

    std::vector<ull> a(n + 1);
    for (int i = 1; i <= n; i++) scanf("%lld", &a[i]);

    auto calc = [&](int mid) -> bool {
        std::vector<ull> b(mid + 1);
        for (int i = 1; i <= mid; i++) b[i] = a[i];
        std::sort(b.begin() + 1, b.end());
        ull sum = 0, sum2 = 0, sigma = 0;
        for (int i = 1; i <= k; i++) sum += b[i], sum2 += b[i] * b[i];
        ull mins = k * sum2 - sum * sum;
        for (int i = k + 1; i <= mid; i++) {
            sum2 += b[i] * b[i], sum2 -= b[i - k] * b[i - k], sum += b[i], sum -= b[i - k];
            mins = std::min(mins, k * sum2 - sum * sum);
        }
        return mins < t;
    };

    int l = k, r = n, ans = -1;
    while (l <= r) {
        int mid = (l + r) >> 1;
        if (calc(mid)) r = mid - 1, ans = mid;
        else l = mid + 1;
    }

    printf("%d\n", ans);

    return 0;
}