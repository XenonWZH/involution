#include <bits/stdc++.h>

namespace XenonWZH {
    void solve() {
        int n;
        scanf("%d", &n);

        std::vector<int> a(n);
        for (int i = 0; i < n; i++) scanf("%d", &a[i]);

        std::vector<int> cnt(n + 1, 0);
        for (int i = 0; i < n; i++) cnt[a[i]]++;

        auto tmp = std::max_element(cnt.begin(), cnt.end());
        *tmp = 0;

        if (n % 2 == 0 && *std::max_element(cnt.begin(), cnt.end()) == n / 2 && n > 2) printf("%d\n", (n - 2) / 2 + 2);
        else printf("%d\n", n);
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