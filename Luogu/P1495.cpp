#include <cstdio>
#include <iostream>

typedef unsigned long long ull;
typedef long long ll;

const int MAXN = 10;

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

int main() {
    int n;
    static long long a[MAXN + 10], r[MAXN + 10];

    std::cin >> n;

    for (int i = 1; i <= n; i++) {
        std::cin >> r[i] >> a[i];
    }

    std::cout << crt(n, a, r);

    return 0;
}