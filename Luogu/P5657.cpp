// P5657 [CSP-S2019] 格雷码
// WzhDnwzWzh

#include <iostream>

typedef unsigned long long ull;

ull power(int m, int n) {
    ull ans = 1;
    while (n > 0) {
        ans *= m;
        n--;
    }
    return ans;
}

void dfs(int n, ull k) {
    if (n == 0) return;
    if (k < power(2, n - 1)) {
        std::cout << "0";
        dfs(n - 1, k);
    }
    else {
        std::cout << "1";
        dfs(n - 1, 2 * power(2, n - 1) - 1 - k);
    }
}

int main() {
    int n;
    ull k;
    std::cin >> n >> k;
    dfs(n, k);
    std::cout << std::endl;
    return 0;
}