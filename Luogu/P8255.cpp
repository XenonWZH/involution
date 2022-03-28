#include <cstdio>
#include <cmath>
#include <iostream>

typedef long long ll;

ll gcd(__int128_t a, __int128_t b) {
    if (b == 0) return a;
    return gcd(b, a % b);
}

int main() {
    int t;

    std::cin >> t;

    while (t--) {
        ll x, z;

        scanf("%lld%lld", &x, &z);

        if (z % x != 0) {
            printf("-1\n");
            continue;
        }

        ll g = gcd(z, (__int128_t)x * x * x);
        ll n = z / g;
        ll m = sqrt((__int128_t)x * x * x / g);

        if (sqrt((__int128_t)x * x * x / g) != m) printf("-1\n");
        else printf("%lld\n", n * x / m);
    }

    return 0;
}