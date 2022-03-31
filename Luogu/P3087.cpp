#include <cstdio>
#include <iostream>

typedef long long ll;

const int MAXN = 100000;

static ll fact[MAXN + 1], inv[MAXN + 1];

ll power(ll x, ll y, ll p) {
    ll re = 1;
    while (y) {
        if (y & 1) re = (re * x) % p;
        x = (x * x) % p;
        y >>= 1;
    }
    return re;
}

ll C(ll x, ll y, ll p) {
    if (x > y) return 0;
    return ((fact[y] * inv[x]) % p * inv[y - x]) % p;
}

ll lucas(ll n, ll m, ll p) {
    if (!n) return 1;
    return (lucas(n / p, m / p, p) * C(n % p, m % p, p)) % p;
}

int main() {
    int t;
    std::cin >> t;

    while (t--) {
        ll n, m, p;

        scanf("%lld%lld%lld", &n, &m, &p);

        fact[0] = 1;
        for (ll i = 1; i <= p; i++) {
            fact[i] = (fact[i - 1] * i) % p;
        }

        inv[p - 1] = power(fact[p - 1], p - 2, p);
        for (ll i = p - 2; i >= 0; i--) {
            inv[i] = (inv[i + 1] * (i + 1)) % p;
        }

        printf("%lld\n", lucas(n, n + m, p));
    }

    return 0;
}