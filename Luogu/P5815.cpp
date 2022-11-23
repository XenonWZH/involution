#include <bits/stdc++.h>

namespace XenonWZH {
    int main() {
        int n;
        long long m;
        scanf("%d %lld", &n, &m);

        std::vector<long long> c(n);
        long long max = 0;
        for (int i = 0; i < n; i++) {
            scanf("%lld", &c[i]);
            max = std::max(max, c[i]);
        }

        auto check = [&](long long limit) {
            long long res = 0;
            for (int i = 0; i < n; i++) res += std::max(0ll, limit - c[i]);
            return res <= m && res <= limit;
        };

        long long l = 0, r = max + m;
        while (l < r) {
            int mid = l + (r - l + 1) / 2;
            if (check(mid)) l = mid;
            else r = mid - 1;
        }

        printf("%lld\n", l);

        return 0;
    }
}

int main() {
    return XenonWZH::main();
}