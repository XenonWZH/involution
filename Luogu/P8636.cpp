#include <bits/stdc++.h>

typedef long long ll;

ll gcd(ll a, ll b) {
    return b == 0 ? a : gcd(b, a % b);
}

ll power(ll a, ll b) {
    ll ans = 1;
    for (; b; b >>= 1, a *= a) if (b & 1) ans *= a;
    return ans;
}

ll calc(ll x) {
    if (x == 1) return 1;
    std::vector<std::pair<ll, int>> p;
    for (int i = 2; (ll)i * i <= x; i++) {
        std::pair<ll, int> t = std::make_pair(i, 0);
        while (x % i == 0) {
            t.second++;
            x /= i;
        }
        if (t.second) p.push_back(t);
    }
    if (p.empty()) return x;
    else {
        if (x > 1) p.emplace_back(x, 1);
        ll g = p[0].second;
        for (auto [u, v] : p) g = gcd(g, v);
        ll ans = 1;
        for (auto [u, v] : p) ans *= power(u, v / g);
        return ans;
    }
}

int main() {
    int n;
    scanf("%d", &n);

    std::vector<ll> a(n);
    for (int i = 0; i < n; i++) scanf("%lld", &a[i]);

    std::sort(a.begin(), a.end());
    n = std::unique(a.begin(), a.end()) - a.begin();

    ll p = a[1] / gcd(a[0], a[1]), q = a[0] / gcd(a[0], a[1]);
    ll pt = calc(p), qt = calc(q);
    ll pp = (pt == 1 ? 1 : round(log(p) / log(pt))), qp = (qt == 1 ? 1 : round(log(q) / log(qt)));

    for (int i = 0; i < n - 1; i++) {
        ll px = a[i + 1] / gcd(a[i], a[i + 1]), qx = a[i] / gcd(a[i], a[i + 1]);
        pp = gcd(pp, round(log(px) / log(pt))), qp = gcd(qp, round(log(qx) / log(qt)));
    }

    printf("%lld/%lld\n", power(pt, pp), power(qt, qp));

    return 0;
}