#include <cstdio>

int main() {
    long long n;
    int k;
    scanf("%lld %d", &n, &k);

    if (n < k) {
        printf("%lld\n", k - n);
        return 0;
    }

    auto lowbit = [&](long long x) {
        return x & -x;
    };

    auto popcnt = [&](long long x) {
        int ans = 0;
        while (x) ans++, x -= lowbit(x);
        return ans;
    };

    long long ans = 0;
    while (popcnt(n) > k) ans += lowbit(n), n += lowbit(n);

    printf("%lld\n", ans);

    return 0;
}