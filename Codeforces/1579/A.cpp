// A. Casimir's String Solitaire
// WzhDnwzWzh

#include <iostream>

int main() {
    int t;

    std::cin >> t;
    while (t--) {
        std::string str;
        std::cin >> str;

        int a = 0, b = 0, c = 0;
        for (char each : str) {
            if (each == 'A') a++;
            if (each == 'B') b++;
            if (each == 'C') c++;
        }

        if (a + c == b) std::cout << "YES" << std::endl;
        else std::cout << "NO" << std::endl;
    }

    return 0;
}