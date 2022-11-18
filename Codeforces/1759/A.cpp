#include <bits/stdc++.h>

namespace XenonWZH {
    void solve() {
        std::string s;
        std::cin >> s;

        int n = s.length();
        for (int i = 0; i < n - 1; i++) {
            if (s[i] == 'Y') {
                if (s[i + 1] != 'e') {
                    puts("NO");
                    return;
                }
            } else if (s[i] == 'e') {
                if (s[i + 1] != 's') {
                    puts("NO");
                    return;
                }
            } else if (s[i] == 's') {
                if (s[i + 1] != 'Y') {
                    puts("NO");
                    return;
                }
            } else {
                puts("NO");
                return;
            }
        }

        puts(s[n - 1] != 'Y' && s[n - 1] != 'e' && s[n - 1] != 's' ? "NO" : "YES");
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