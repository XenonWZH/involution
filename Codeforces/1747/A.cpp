#include <bits/stdc++.h>

namespace XenonWZH {
    void solve() {
        int n;
        scanf("%d", &n);

        std::vector<long long> a(n);
        for (int i = 0; i < n; i++) scanf("%lld", &a[i]);

        long long s = 0;
        for (int i = 0; i < n; i++) s += a[i];

        printf("%lld\n", std::abs(s));
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