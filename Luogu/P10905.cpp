#include <iostream>

void solve() {
    std::string s;
    std::cin >> s;

    int n = s.length();
    int p = 0, q = n - 1;
    while (p < n && (s[p] == 'l' || s[p] == 'q' || s[p] == 'b')) p++;
    if (p == n) {
        std::cout << "Yes\n";
        return;
    } else while (s[q] == 'l' || s[q] == 'q' || s[q] == 'b') q--;

    for (int i = p; i <= q; i++) {
        if (s[i] != s[q + p - i]) {
            std::cout << "No\n";
            return;
        }
    }

    while (true) {
        p--, q++;
        if (p < 0 || q >= n) break;
        if (s[p] != s[q]) {
            std::cout << "No\n";
            return;
        }
    }

    std::cout << (p >= 0 ? "No" : "Yes") << '\n';
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