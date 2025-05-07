#include <bits/stdc++.h>

namespace XenonWZH {
typedef long long ll;

void solve() {
    int n;
    std::cin >> n;

    std::string s;
    std::cin >> s;

    if (s.front() != s.back()) std::cout << "empty\n";
    else {
        if (s.front() == '0') {
            s = s + '1';
            int cnt = 0, ans = INT_MAX;
            for (auto c : s) {
                if (c == '1') ans = std::min(ans, cnt), cnt = 0;
                else cnt++;
            }
            if (ans == 0) std::cout << "empty\n";
            else {
                for (int i = 0; i < ans; i++) std::cout << '0';
                std::cout << '\n';
            }
        } else {
            s = s + '0';
            int cnt = 0, ans = INT_MAX;
            for (auto c : s) {
                if (c == '0') ans = std::min(ans, cnt), cnt = 0;
                else cnt++;
            }
            if (ans == 0) std::cout << "empty\n";
            else {
                for (int i = 0; i < ans; i++) std::cout << '1';
                std::cout << '\n';
            }
        }
    }
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