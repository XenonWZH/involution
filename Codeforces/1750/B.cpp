#include <bits/stdc++.h>

namespace XenonWZH {
    void solve() {
        int n;
        std::cin >> n;

        std::string s;
        std::cin >> s;

        long long maxx = 0, maxy = 0, res = 0;
        for (int i = 0; i < n; i++) {
            if (s[i] == '0') {
                res++;
                maxx = std::max(maxx, res);
            } else res = 0;
        }
        res = 0;
        for (int i = 0; i < n; i++) {
            if (s[i] == '1') {
                res++;
                maxy = std::max(maxy, res);
            } else res = 0;
        }

        long long cntx = 0, cnty = 0;
        for (int i = 0; i < n; i++) {
            if (s[i] == '0') cntx++;
            else cnty++;
        }

        std::cout << std::max(std::max(maxx * maxx, maxy * maxy), cntx * cnty) << '\n';
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