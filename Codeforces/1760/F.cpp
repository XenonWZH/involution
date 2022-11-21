#include <bits/stdc++.h>

namespace XenonWZH {
    void solve() {
        int n;
        long long c, d;
        scanf("%d %lld %lld", &n, &c, &d);

        std::vector<long long> a(n);
        for (int i = 0; i < n; i++) scanf("%lld", &a[i]);
        std::sort(a.begin(), a.end());

        if (a[n - 1] * d < c) {
            puts("Impossible");
            return;
        }

        long long s = 0;
        for (int i = n - 1; i >= std::max(0ll, n - d); i--) s += a[i];
        if (s >= c) {
            puts("Infinity");
            return;
        }

        long long l = 0, r = d;
        while (l < r) {
            int mid = l + (r - l + 1) / 2;

            int cnt = 0;
            long long res = 0;
            for (int i = 0; i < d; i++) {
                cnt++;
                if (cnt <= n) res += a[n - cnt];
                if (cnt == mid + 1) cnt = 0;
            }

            if (res >= c) l = mid;
            else r = mid - 1;
        }

        printf("%lld\n", l);
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