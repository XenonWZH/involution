#include <bits/stdc++.h>

int main() {
    int n;
    long long t;
    scanf("%d %lld", &n, &t);

    long long ans = 2;
    for (int i = 1; i <= n; i++) {
        long long x;
        scanf("%lld", &x);
        ans = std::max(ans, (long long)std::ceil(x * 1.0 / t));
    }

    printf("%lld\n", ans);

    return 0;
}