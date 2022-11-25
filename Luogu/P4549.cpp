#include <cstdio>
#include <vector>
#include <algorithm>

int main() {
    int n;
    scanf("%d", &n);

    long long ans;
    scanf("%lld", &ans);
    for (int i = 1; i < n; i++) {
        long long a;
        scanf("%lld", &a);
        ans = std::__gcd(ans, std::abs(a));
    }

    printf("%lld\n", ans);

    return 0;
}