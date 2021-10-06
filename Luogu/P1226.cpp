// P1226 【模板】快速幂||取余运算
// WzhDnwzWzh

#include <iostream>

int power(int a, int b,int p) {
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

int main() {
    int a, b, p;
    std::cin >> a >> b >> p;
    std::cout << a << "^" << b << " mod " << p << "=" << power(a, b, p) << std::endl;
    return 0;
}