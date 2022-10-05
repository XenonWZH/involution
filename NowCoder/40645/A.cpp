#include <cstdio>
#include <iostream>

int a, b, c, d;

bool check(int limit) {
    for (int i = 0; i <= std::max(std::max(a, 4 * d), std::max(2 * b, 2 * d)); i++) {
        for (int j = 0; j <= std::max(std::max(4 * a, d), std::max(2 * b, 2 * d)); j++) {
            if (i + j > limit) continue;
            if ((limit - i - j) / 2 < std::max(a - i - j / 4, d - i / 4 - j)) continue;

            int res = limit - i - j;
            int y = std::max(0, b - i / 2 - j / 2), z = std::max(0, c - i / 2 - j / 2);
            for (int k = 0; k <= res; k++) {
                if (k + (res - k) / 4 >= y && k / 4 + res - k >= z) {
                    return true;
                }
            }
        }
    }

    return false;
}

int main() {
    scanf("%d %d %d %d", &a, &b, &c, &d);

    int l = 1, r = a + b + c + d;
    while (l < r) {
        int mid = l + (r - l) / 2;
        if (check(mid)) r = mid;
        else l = mid + 1;
    }

    printf("%d\n", l);

    return 0;
}