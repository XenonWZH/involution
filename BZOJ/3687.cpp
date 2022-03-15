#include <cstdio>
#include <iostream>
#include <bitset>

const int MAXN = 1000, MAXA = 2000000;

int main() {
    int n, a;

    std::cin >> n;

    static std::bitset<MAXA + 1> bits;
    bits[0] = 1;

    for (int i = 1; i <= n; i++) {
        scanf("%d", &a);
        bits = bits ^ (bits << a);
    }

    long long ans = 0;
    for (int i = 1; i <= MAXA; i++) {
        if (bits[i]) {
            ans ^= i;
        }
    }

    std::cout << ans << std::endl;

    return 0;
}