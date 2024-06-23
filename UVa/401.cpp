#include <iostream>
#include <string>
#include <map>

std::map<char, char> list = { {'A', 'A'}, {'E', '3'}, {'H', 'H'}, {'I', 'I'}, {'J', 'L'}, {'L', 'J'}, {'M', 'M'}, {'O', 'O'}, {'S', '2'}, {'T', 'T'}, {'U', 'U'}, {'V', 'V'}, {'W', 'W'}, {'X', 'X'}, {'Y', 'Y'}, {'Z', '5'}, {'1', '1'}, {'2', 'S'}, {'3', 'E'}, {'5', 'Z'}, {'8', '8'} };

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    std::string s;

    while (std::cin >> s) {
        int len = s.length();
        bool mir = true, pal = true;

        for (int i = 0; i < len; i++) {
            if (s[len - i - 1] != list[s[i]]) mir = false;
            if (s[len - i - 1] != s[i]) pal = false;
        }

        std::cout << s << " -- ";
        if (mir && pal) std::cout << "is a mirrored palindrome.\n";
        else if (mir) std::cout << "is a mirrored string.\n";
        else if (pal) std::cout << "is a regular palindrome.\n";
        else std::cout << "is not a palindrome.\n";
        std::cout << '\n';
    }

    return 0;
}