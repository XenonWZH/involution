// #7. Input Test
// WzhDnwzWzh

#include <iostream>

const int MAXN = 3000000;

int main() {
    long long x, ans = 0;

    for (int i = 0; i < MAXN; i++) {
        std::cin >> x;
        ans ^= x;
    }

    std::cout << ans << std::endl;

    return 0;
}
