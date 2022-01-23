#include <iostream>
#include <algorithm>

const int MAXN = 27;

int main() {
    int n;
    static std::string str[MAXN];

    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    std::cout.tie(0);

    std::cin >> n;
    for (int i = 0; i < n; i++) {
        std::cin >> str[i];
    }

    std::sort(str, str + n);

    for (int i = 0; i < n; i++) {
        std::cout << str[i] << " ";
    }
    std::cout << '\n';

    return 0;
}