#include <iostream>

int main() {
    std::string s;
    int ans = 0;
    for (int i = 1; i <= 12; i++) {
        std::cin >> s;
        if (s.length() == i) ans++;
    }
    std::cout << ans << "\n";
    return 0;
}