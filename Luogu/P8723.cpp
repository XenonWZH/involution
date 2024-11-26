#include <iostream>

std::string calc(int n, int a) {
    std::string ans = "";
    while (a > 0) {
        int x = a % n;
        ans = (char)(x < 10 ? x + '0' : x - 10 + 'A') + ans;
        a /= n;
    }
    return ans;
}

int main() {
    int n;
    std::cin >> n;

    for (int i = 1; i < n; i++) {
        for (int j = 1; j <= i; j++) {
            std::cout << calc(n, i) << '*' << calc(n, j) << '=' << calc(n, i * j) << ' ';
        }
        std::cout << '\n';
    }
    return 0;
}