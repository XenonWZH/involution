#include <bits/stdc++.h>

namespace XenonWZH {
    const int MOD = 998244353;

    int counts(int n, int m) {
        std::vector<int> p;
        for (int i = 2; i * i <= m; i++) {
            if (m % i == 0) {
                p.push_back(i);
                while (m % i == 0) m /= i;
            }
        }
        if (m > 1) p.push_back(m);

        int ans = 0, len = p.size();
        for (int i = 1; i < (1 << len); i++) {
            int tmp = 1, t = 0;
            for (int j = 0; j < len; j++) {
                if (i & (1 << j)) {
                    tmp *= p[j];
                    t++;
                }
            }
            ans += (t & 1 ? n / tmp : -n / tmp);
        }
        return n - ans;
    }

    void solve() {
        int n, m;
        scanf("%d %d", &n, &m);

        std::vector<int> a(n);
        for (int i = 0; i < n; i++) scanf("%d", &a[i]);

        if (n == 1) {
            puts("1");
            return;
        }

        for (int i = 0; i < n - 1; i++) {
            if (a[i] % a[i + 1]) {
                puts("0");
                return;
            }
        }

        long long ans = 1;
        for (int i = 1; i < n; i++) {
            ans = ans * counts(m / a[i], a[i - 1] / a[i]) % MOD;
        }

        printf("%lld\n", ans);
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