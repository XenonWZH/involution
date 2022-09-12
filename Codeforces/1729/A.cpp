#include <cstdio>
#include <cmath>
#include <iostream>

int main() {
    int t;

    scanf("%d", &t);

    while (t--) {
        int a, b, c;
        scanf("%d %d %d", &a, &b, &c);
        int x = a, y = std::abs(b - c) + c;
        if (x < y) puts("1");
        else if (x > y) puts("2");
        else puts("3");
    }

    return 0;
}