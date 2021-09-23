// 0102 64位整数乘法
// WzhDnwzWzh

#include <iostream>

typedef unsigned long long ull;

ull mul(ull a, ull b, ull p) {
    ull ans = 0;
    while (b > 0) {
        if (b & 1 == 1) {
            ans = (ans + a) % p;
        }
        a = (a * 2) % p;
        b >>= 1;
    }
    return ans;
}

int main() {
    ull a, b, p;
    std::cin >> a >> b >> p;
    std::cout << mul(a, b, p) << std::endl;
    return 0;
}