#include <cstdio>

typedef __int128 ll;
const int MAXN = 1e5;

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

ll excrt(int n, ll a[], ll m[]) {
    ll na = a[1], nm = m[1];
    for (int i = 2; i <= n; i++) {
        ll p, q;
        ll d = exgcd(nm, m[i], p, q);
        p *= (na - a[i]) / d, q *= (na - a[i]) / d;
        nm = nm / d * m[i];
        na = (a[i] + q * m[i] % nm) % nm;
    }

    ll p, q;
    exgcd(1, nm, p, q);
    return ((p * na) % nm + nm) % nm;
}

int main() {
    int n;
    scanf("%d", &n);

    static ll a[MAXN + 1], m[MAXN + 1];
    for (int i = 1; i <= n; i++) {
        long long ta, tm;
        scanf("%lld %lld", &tm, &ta);
        a[i] = ta, m[i] = tm;
    }

    printf("%lld\n", (long long)excrt(n, a, m));

    return 0;
}