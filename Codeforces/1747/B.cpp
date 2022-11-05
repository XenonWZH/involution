#include <bits/stdc++.h>

namespace XenonWZH {
    void solve() {
        int n;
        scanf("%d", &n);

        std::vector<std::pair<int, int>> ans;
        int l = 1, r = n;
        while (l <= r) {
            ans.push_back(std::make_pair(3 * (l - 1) + 1, 3 * r));
            l++, r--;
        }

        printf("%zu\n", ans.size());
        for (auto each : ans) {
            printf("%d %d\n", each.first, each.second);
        }
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