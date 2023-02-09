#include <cstdio>
#include <cmath>

typedef long long ll;

ll exgcd(ll a, ll b, ll &x, ll &y) {
    if (b == 0) {
        x = 1, y = 0;
        return a;
    }
    ll d = exgcd(b, a % b, x, y);
    ll z = x;
    x = y, y = z - (a / b) * y;
    return d;
}

void solve() {
    ll a, b, c, x, y;
    scanf("%lld %lld %lld", &a, &b, &c);

    ll g = exgcd(a, b, x, y);
    if (c % g != 0) {
        puts("-1");
        return;
    }

    x *= c / g, y *= c / g;
    a /= g, b /= g;
    if ((ll)ceil((-x + 1.0) / b) > (ll)floor((y - 1.0) / a)) printf("%lld %lld\n", x + b * (ll)ceil((-x + 1.0) / b), y - a * (ll)floor((y - 1.0) / a));
    else {
        printf("%lld %lld %lld %lld %lld\n", (ll)floor((y - 1.0) / a) - (ll)ceil((-x + 1.0) / b) + 1, x + b * (ll)ceil((-x + 1.0) / b), y - a * (ll)floor((y - 1.0) / a), x + b * (ll)floor((y - 1.0) / a), y - a * (ll)ceil((-x + 1.0) / b));
    }
}

int main() {
    int t;
    scanf("%d", &t);

    while (t--) solve();

    return 0;
}