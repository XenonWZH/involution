#include <climits>
#include <iostream>
#include <string>

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    int t;

    std::cin >> t;

    while (t--) {
        std::string s;
        std::cin >> s;

        int l = s.length();
        std::string min;
        for (int i = 0; i < l; i++) min += 'T';
        s += s;
        for (int i = 0; i < l; i++) {
            std::string t;
            for (int j = i; j < i + l; j++) t += s[j];
            if (t < min) min = t;
        }

        std::cout << min << '\n';
    }

    return 0;
}