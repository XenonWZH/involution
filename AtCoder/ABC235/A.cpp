// A - Rotate
// XenonWZH

#include <iostream>

int main() {
    int num;

    std::cin >> num;

    int a = num % 10, b = num / 10 % 10, c = num / 100;
    int ans = 0;
    ans += c + b * 10 + a * 100;
    ans += a + c * 10 + b * 100;
    ans += b + a * 10 + c * 100;

    std::cout << ans << std::endl;

    return 0;
}