#include <cstdio>
#include <algorithm>

int main() {
    long long n, k;

    scanf("%lld %lld", &n, &k);

    long long ans = n * k;
    for (long long l = 1, r; l <= n; l = r + 1) {
        r = l > k ? n : std::min(k / (k / l), n);
        ans -= (l + r) * (r - l + 1) / 2 * (k / l);
    }

    printf("%lld\n", ans);

    return 0;
}