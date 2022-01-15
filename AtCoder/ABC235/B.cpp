// B - Climbing Takahashi
// XenonWZH

#include <iostream>

int main() {
    int n, h = -1, input;

    std::cin >> n;

    while (n--) {
        std::cin >> input;
        if (input > h) h = input;
        else break;
    }

    std::cout << h << std::endl;

    return 0;
}