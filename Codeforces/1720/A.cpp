#include <cstdio>
#include <cmath>

int main() {
    int t;

    scanf("%d", &t);

    while (t--) {
        long long a, b, c, d;

        scanf("%lld %lld %lld %lld", &a, &b, &c, &d);

        long long x = a * d, y = b * c;

        if (x == y) puts("0");
        else if (x == 0 || y == 0) puts("1");
        else if ((x / y) * y == x || (y / x) * x == y) puts("1");
        else puts("2");
    }

    return 0;
}