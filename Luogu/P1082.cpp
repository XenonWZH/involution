#include <cstdio>
#include <iostream>

int exgcd(int a, int b, int &x, int &y) {
    if (!b) {
        x = 1;
        y = 0;
        return a;
    }
    int d = exgcd(b, a % b, x, y);
    int t = x;
    x = y;
    y = t - (a / b) * y;
    return d;
}

int gcd(int a, int b) {
    if (b == 0) return a;
    return gcd(b, a % b);
}
int main() {
    int a, b;
    std::cin >> a >> b;

    int x, y;
    exgcd(a / gcd(a, b), b / gcd(a, b), x, y);

    std::cout << (x % b + b) % b * gcd(a, b) << std::endl;

    return 0;
}