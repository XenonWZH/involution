#include <bits/stdc++.h>

namespace XenonWZH {
    void solve() {
        int n;
        scanf("%d", &n);

        std::vector<long long> a(n);
        for (int i = 0; i < n; i++) scanf("%lld", &a[i]);

        long long min = 2 * a[0];
        for (int i = 1; i < n; i++) min = std::min(min, 2 * a[i] + 1);

        if (min & 1) puts("Alice");
        else puts("Bob");
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