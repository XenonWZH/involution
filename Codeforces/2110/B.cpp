#include <bits/stdc++.h>

namespace XenonWZH {
typedef long long ll;

const int MAXN = 1e5;
const int MOD = 998244353;

void solve() {
    std::string s;
    std::cin >> s;

    int n = s.size();
    int x = 1;
    for (int i = 1; i < n; i++) {
        if (s[i] == '(') x++;
        else x--;

        if (x == 0 && i != n - 1) {
            std::cout << "YES\n";
            return;
        }
    }

    std::cout << "NO\n";
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    int t;
    std::cin >> t;

    while (t--) solve();

    return 0;
}
};

int main() { return XenonWZH::main(); }