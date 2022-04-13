#include <iostream>

typedef long long ll;

const int MAXN = 35617, MOD = 999911659;

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
    if (x < y) return 0;
    return ((fact[x] * inv[y]) % p * inv[x - y]) % p;
}

ll lucas(ll n, ll m, ll p) {
    if (n < m) return 0;
    if (!n) return 1;
    return (lucas(n / p, m / p, p) * C(n % p, m % p, p)) % p;
}

int exgcd(ll a, ll b, ll &x, ll &y) {
    if (!b) {
        x = 1;
        y = 0;
        return a;
    }
    ll d = exgcd(b, a % b, x, y);
    ll t = x;
    x = y;
    y = t - (a / b) * y;
    return d;
}

ll crt(int k, ll* a, ll* r) {
    ll n = 1, ans = 0;
    for (int i = 1; i <= k; i++) n = n * r[i];
    for (int i = 1; i <= k; i++) {
        ll m = n / r[i], b, y;
        exgcd(m, r[i], b, y);
        ans = (ans + a[i] * m * b % n) % n;
    }
    return (ans % n + n) % n;
}

void init(int p) {
    fact[0] = 1;
    for (ll i = 1; i <= p; i++) {
        fact[i] = (fact[i - 1] * i) % p;
    }

    inv[p - 1] = power(fact[p - 1], p - 2, p);
    for (ll i = p - 2; i >= 0; i--) {
        inv[i] = (inv[i + 1] * (i + 1)) % p;
    }
}

int main() {
    ll n, g;

    std::cin >> n >> g;

    if (g == MOD) {
        std::cout << "0" << std::endl;
        return 0;
    }

    static ll f[5] = { -1, 2, 3, 4679, 35617 }, a[5];

    for (int i = 1; i <= 4; i++) {
        init(f[i]);

        for (ll d = 1; d * d <= n; d++) {
            if (n % d == 0) {
                a[i] = (a[i] + lucas(n, d, f[i])) % f[i];
                if (d * d != n) {
                    a[i] = (a[i] + lucas(n, n / d, f[i])) % f[i];
                }
            }
        }
    }

    std::cout << power(g, crt(4, a, f), MOD) << std::endl;

    return 0;
}