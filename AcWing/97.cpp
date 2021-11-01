// 97. 约数之和
// WzhDnwzWzh

#include <iostream>

const int MOD = 9901;

int power(int a, int b, int p) {
    int ans = 1 % p;
    while (b > 0) {
        if (b & 1 == 1) {
            ans = ((long long)ans * a) % p;
        }
        a = ((long long)a * a) % p;
        b >>= 1;
    }
    return ans;
}

int sum(int p, int c) {
    if (c == 1) {
        return p + 1;
    } else if (c == 0) {
        return 1;
    } else if (c % 2) {
        return ((1 + power(p, (c + 1) / 2, MOD)) * sum(p, (c - 1) / 2)) % MOD;
    } else {
        return ((1 + power(p, c / 2, MOD)) * sum(p, c / 2 - 1) + power(p, c, MOD)) % MOD;
    }
}

int main() {
    int a, b;

    std::cin >> a >> b;

    int ans = 1;
    for (int i = 2; i <= a; i++) {
        int c = 0;

        while (a % i == 0) {
            c++;
            a /= i;
        }
        if (c > 0) ans = (ans * sum(i, b * c)) % 9901;
    }

    std::cout << (a == 0 ? 0 : ans) << std::endl;

    return 0;
}