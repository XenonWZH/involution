#include <cstdio>
#include <cmath>
#include <climits>
#include <iostream>

void solve() {
    long long a, b;

    scanf("%lld %lld", &a, &b);

    if(a > b) {
        printf("%lld\n", a - b);
        return;
    }

    long long ans = LLONG_MAX;
    if(a <= sqrt(b)) {
        for(long long i = 0; i <= a; i++) {
            long long w = a + i;
            long long k = (b + w - 1) / w;
            ans = std::min(ans, i + w * k - b);
        }
    } else {
        for(long long i = 1; i <= (a + b - 1) / a; i++) {
            long long w = (b + i - 1) / i;
            if(w < a) ans = std::min(ans, a * i - b);
            else ans = std::min(ans, w - a + w * i - b);
        }
    }

    printf("%lld\n", ans);
}

int main() {
    int t;

    scanf("%d", &t);

    while (t--) solve();

    return 0;
}