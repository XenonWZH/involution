// #2611. 「NOIP2013」积木大赛
// WzhDnwzWzh

#include <iostream>

int main() {
    int cube[100000], n;

    std::cin >> n >> cube[0];
    int ans = cube[0];
    for (int i = 1; i < n; i++) {
        std::cin >> cube[i];
        ans += cube[i] - cube[i - 1] > 0 ? cube[i] - cube[i - 1] : 0;
    }

    std::cout << ans << std::endl;
    return 0;
}