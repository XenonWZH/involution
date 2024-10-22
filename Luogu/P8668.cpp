#include <bits/stdc++.h>

typedef long long ll;

int main() {
    ll x, y;
    scanf("%lld %lld", &x, &y);

    if (x == y && x == 0) {
        puts("0");
        return 0;
    }

    ll ans = 0;

    if (std::abs(x) <= 1000 && std::abs(y) <= 1000) {
        ll a = 0, b = 0;
        ll sta = 3, step = 0;

        while (true) {
            sta = (sta + 1) % 4;
            if (sta % 2 == 0) step++;
            if (sta == 0) {
                if (b == y && x >= a - step && x < a) {
                    ans += a - x;
                    break;
                }
                ans += step;
                a -= step;
            } else if (sta == 1) {
                if (a == x && y > b && y <= b + step) {
                    ans += y - b;
                    break;
                }
                ans += step;
                b += step;
            } else if (sta == 2) {
                if (b == y && x > a && x <= a + step) {
                    ans += x - a;
                    break;
                }
                ans += step;
                a += step;
            } else {
                if (a == x && y < b && y >= b - step) {
                    ans += b - y;
                    break;
                }
                ans += step;
                b -= step;
            }
        }
    } else {
        ll n = std::max(std::abs(x), std::abs(y)) - 3;
        ll a = n, b = -n;
        ll sta = 3, step = 2 * n;
        ans = 2 * n * (2 * n + 1);

        while (true) {
            sta = (sta + 1) % 4;
            if (sta % 2 == 0) step++;
            if (sta == 0) {
                if (b == y && x >= a - step && x < a) {
                    ans += a - x;
                    break;
                }
                ans += step;
                a -= step;
            } else if (sta == 1) {
                if (a == x && y > b && y <= b + step) {
                    ans += y - b;
                    break;
                }
                ans += step;
                b += step;
            } else if (sta == 2) {
                if (b == y && x > a && x <= a + step) {
                    ans += x - a;
                    break;
                }
                ans += step;
                a += step;
            } else {
                if (a == x && y < b && y >= b - step) {
                    ans += b - y;
                    break;
                }
                ans += step;
                b -= step;
            }
        }
    }

    printf("%lld\n", ans);

    return 0;
}