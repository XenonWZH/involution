#include <bits/stdc++.h>

namespace XenonWZH {
typedef long long ll;

ll gcd(ll a, ll b) {
    return b ? gcd(b, a % b) : a;
}

void solve() {
    ll b, d;
    scanf("%lld %lld", &b, &d);

    // a * d + b * c = b * b
    // 0 * d + b * b = b * b

    ll g = gcd(b, d);
    ll m = d / g;

    if (b % m == 0) printf("%lld\n", b / m - 1);
    else printf("%lld\n", b / m);
}

int main() {
    int t;

    scanf("%d", &t);

    while (t--) solve();

    return 0;
}
}

int main() {
    return XenonWZH::main();
}