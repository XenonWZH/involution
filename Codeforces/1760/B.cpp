#include <bits/stdc++.h>

namespace XenonWZH {
    void solve() {
        int n;
        scanf("%d", &n);

        std::string s;
        std::cin >> s;

        int ans = 0;
        for (int i = 0; i < n; i++) ans = std::max(ans, s[i] - 'a' + 1);

        printf("%d\n", ans);
    }

    int main() {
        int t;

        scanf("%d", &t);

        while (t--) solve();

        return 0;
    }
}

int main() {
    return XenonWZH::main();
}