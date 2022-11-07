#include <bits/stdc++.h>

namespace XenonWZH {
    void solve() {
        int n;
        std::cin >> n;

        std::string sa, sb;
        std::cin >> sa >> sb;

        std::vector<int> a(n), b(n);
        for (int i = 0; i < n; i++) a[i] = sa[i] - '0', b[i] = sb[i] - '0';

        if (a[0] == b[0]) {
            for (int i = 1; i < n; i++) {
                if (a[i] != b[i]) {
                    std::cout << "NO" << '\n';
                    return;
                }
            }
        } else {
            for (int i = 1; i < n; i++) {
                if (a[i] == b[i]) {
                    std::cout << "NO" << '\n';
                    return;
                }
            }
        }

        std::cout << "YES" << '\n';

        std::vector<std::pair<int, int>> ans;
        bool flag = a[0] != b[0];

        for (int i = 0; i < n; i++) {
            if (a[i]) {
                ans.push_back(std::make_pair(i + 1, i + 1));
                flag ^= true;
            }
        }

        if (flag) {
            ans.push_back(std::make_pair(1, 1));
            ans.push_back(std::make_pair(2, n));
            ans.push_back(std::make_pair(1, n));
        }

        std::cout << ans.size() << '\n';
        for (auto each : ans) std::cout << each.first << ' ' << each.second << '\n';
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
}

int main() {
    return XenonWZH::main();
}