#include <cstdio>
#include <iostream>

typedef long long ll;

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

int main() {
    ll x, y, m, n, l;
    std::cin >> x >> y >> m >> n >> l;

    ll a = n - m, b = l, c = x - y;
    if (a < 0) a = -a, c = -c;
    ll xAns, yAns;
    ll gcd = exgcd(a, b, xAns, yAns);

    if (c % gcd != 0) std::cout << "Impossible" << std::endl;
    else std::cout << ((c / gcd * xAns) % (b / gcd) + b / gcd) % (b / gcd)<< std::endl;

    return 0;
}