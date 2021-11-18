// P1098 [NOIP2007 提高组] 字符串的展开
// WzhDnwzWzh

#include <cctype>
#include <cmath>
#include <iostream>
#include <string>

int main() {
    int p1, p2, p3;

    std::cin >> p1 >> p2 >> p3;

    std::string str;
    std::cin >> str;

    std::cout << str[0];
    for (int i = 1, len = str.size(); i < len - 1; i++) {
        if (str[i] == '-' && str[i - 1] < str[i + 1] &&
            ((str[i - 1] >= '0' && str[i - 1] <= '9' && str[i + 1] >= '0' && str[i + 1] <= '9') ||
             (str[i - 1] >= 'A' && str[i - 1] <= 'z' && str[i + 1] >= 'A' && str[i + 1] <= 'z'))) {
            if (p1 == 1 || p1 == 2) {
                char str1, str2;
                if (p1 == 1) str1 = tolower(str[i - 1]), str2 = tolower(str[i + 1]);
                else str1 = toupper(str[i - 1]), str2 = toupper(str[i + 1]);
                char start = str1;
                char end = str2;
                if (p3 == 1) for (int j = start + 1; j < end; j++) for (int k = 0; k < p2; k++) std::cout << (char)j;
                else  for (int j = end - 1; j > start; j--) for (int k = 0; k < p2; k++) std::cout << (char)j;
            } else for (int j = 0, r = (str[i + 1] - str[i - 1] - 1) * p2; j < r; j++) std::cout << "*";
        } else std::cout << str[i];
    }
    std::cout << str[str.size() - 1];

    std::cout << std::endl;
    return 0;
}
