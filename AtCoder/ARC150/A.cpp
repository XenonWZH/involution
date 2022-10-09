#include <cstdio>
#include <iostream>
#include <vector>

const int MAXN = 3e5;

void solve() {
    int n, k;
    std::string s;

    std::cin >> n >> k;
    std::cin >> s;

    std::vector<int> one;
    for (int i = 0; i < n; i++) {
        if (s[i] == '1') {
            one.push_back(i);
        }
    }

    if (k == 0) {
        if (one.empty()) std::cout << "Yes\n";
        else std::cout << "No\n";
        return;
    }

    if (one.empty()) {
        int cnt = 0;
        bool valid = false;
        for (int i = 0; i < n; i++) {
            if (s[i] == '?') {
                cnt++;
                if (cnt >= k) {
                    if (valid) {
                        std::cout << "No\n";
                        return;
                    } else valid = true;
                }
            } else cnt = 0;
        }

        if (valid) std::cout << "Yes\n";
        else std::cout << "No\n";
        return;
    }

    if (one.back() - one.front() + 1 > k) {
        std::cout << "No\n";
        return;
    }

    for (int i = one.front(); i <= one.back(); i++) {
        if (s[i] == '0') {
            std::cout << "No\n";
            return;
        }
    }

    int llen = 0, rlen = 0;
    for (int i = one.front() - 1; i >= 0; i--) {
        if (s[i] != '?') break;
        llen++;
    }
    for (int i = one.back() + 1; i < n; i++) {
        if (s[i] != '?') break;
        rlen++;
    }

    if (llen == 0 || rlen == 0 || k == one.back() - one.front() + 1) {
        if (one.back() - one.front() + 1 + llen + rlen >= k) std::cout << "Yes\n";
        else std::cout << "No\n";
    } else {
        if (one.back() - one.front() + 1 + llen + rlen == k) std::cout << "Yes\n";
        else std::cout << "No\n";
    }
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    std::cout.tie(0);

    int t;

    std::cin >> t;

    while (t--) solve();

    return 0;
}