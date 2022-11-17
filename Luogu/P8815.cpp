#include <iostream>
#include <vector>
#include <stack>

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    std::string s;
    std::cin >> s;

    int n = s.length();
    int val = 0, flag = 0;
    int ands = 0, ors = 0;

    for (int i = 0; i < n; i++) {
        if (flag) {
            if (s[i] == '(') {
                int bracket = 1;
                while (bracket) {
                    i++;
                    if (s[i] == '(') bracket++;
                    else if (s[i] == ')') bracket--;
                }
            } else if (flag == 1 && s[i] == '|') flag = 0;
            else if (s[i] == ')') flag = 0;
            else if (flag == 1 && s[i] == '&') ands++;
            else if (flag == 2 && s[i] == '|') ors++;
        } else {
            if (s[i] == '1') val = 1;
            else if (s[i] == '0') val = 0;
            if (val == 0 && s[i] == '&') {
                flag = 1;
                ands++;
            }
            if (val == 1 && s[i] == '|') {
                flag = 2;
                ors++;
            }
        }
    }

    std::cout << val << '\n';
    std::cout << ands << ' ' << ors << '\n';

    return 0;
}