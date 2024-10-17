#include <bits/stdc++.h>

const int MAXN = 1000;

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    std::string a, b;
    std::cin >> a >> b;

    int n = a.length();
    std::bitset<MAXN> x;

    for (int i = 0; i < n; i++) {
        if (a[i] == b[i]) x[i] = 0;
        else x[i] = 1;
    }

    int ans = 0;
    for (int i = 0; i < n - 1; i++) {
        if (x[i]) {
            ans++;
            x[i] = x[i] ^ 1;
            x[i + 1] = x[i + 1] ^ 1;
        }
    }

    std::cout << ans << "\n";

    return 0;
}