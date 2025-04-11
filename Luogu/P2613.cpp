#include <bits/stdc++.h>

typedef long long ll;
const ll MOD = 19260817;

ll exgcd(ll a, ll b, ll &x, ll &y) {
    if (b == 0) {
        x = 1, y = 0;
        return a;
    }
    ll d = exgcd(b, a % b, x, y);
    ll t = y;
    y = x - y * (a / b);
    x = t;
    return d;
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    std::string as, bs;
    std::cin >> as >> bs;

    ll a = 0, b = 0;
    for (char ch : as) a = (a * 10 + ch - '0') % MOD;
    for (char ch : bs) b = (b * 10 + ch - '0') % MOD;

    ll x, y;
    ll d = exgcd(b, MOD, x, y);
    if (a % d == 0) printf("%lld\n", ((x * (a / d)) % MOD + MOD) % MOD);
    else puts("Angry!");

    return 0;
}