#include <cstdio>
#include <iostream>

const int MAXN = 3000000;

int main() {
    int n, p;
    std::cin >> n >> p;

    static long long inv[MAXN + 1];
    inv[1] = 1;
    puts("1");
    for(int i = 2; i <= n; i++) {
        inv[i] = ((long long)p - p / i) * inv[p % i] % p;
        printf("%lld\n", inv[i]);
    }

    return 0;
}