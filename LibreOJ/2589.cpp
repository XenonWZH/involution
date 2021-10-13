// #2589. 「NOIP2009」Hankson 的趣味题
// WzhDnwzWzh

#include <iostream>

int gcd(int a, int b) {
    return b == 0 ? a : gcd(b, a % b);
}

int main() {
    int n, a0, a1, b0, b1;

    std::cin >> n;
    while (n--) {
        std::cin >> a0 >> a1 >> b0 >> b1;

        int ans = 0, p = a0 / a1, q = b1 / b0;
        for (int i = 1; i * i <= b1; i++)
            if (b1 % i == 0) {
                if (i % a1 == 0 && gcd(i / a1, p) == 1 && gcd(q, b1 / i) == 1) ans++;
                int y = b1 / i;
                if (i == y) continue;
                if (y % a1 == 0 && gcd(y / a1, p) == 1 && gcd(q, b1 / y) == 1) ans++;
            }

        std::cout << ans << std::endl;
    }

    return 0;
}