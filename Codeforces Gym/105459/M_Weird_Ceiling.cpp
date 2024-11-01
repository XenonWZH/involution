#include <bits/stdc++.h>

namespace XenonWZH {
    void solve() {
        int n;
        scanf("%d", &n);

        std::vector<int> p;
        int m = n;
        for (int i = 2; 1ll * i * i <= m; i++) {
            while (m % i == 0) {
                p.push_back(i);
                m /= i;
            }
        }
        if (m != 1) p.push_back(m);

        int t = p.size();
        std::vector<int> mul;
        for (int i = 0; i < (1 << t); i++) {
            long long s = 1;
            for (int j = 0; j < t; j++) {
                if ((i >> j) & 1) {
                    s *= p[j];
                }
            }
            mul.push_back(s);
        }

        std::sort(mul.begin(), mul.end(), std::greater<int>());
        int tt = mul.size();
        long long ans = 0;
        for (int i = 0; i < tt - 1; i++) ans += 1ll * (mul[i] - mul[i + 1]) * (n / mul[i + 1]);
        ans++;

        printf("%lld\n", ans);
    }

    int main() {
        int t;
        scanf("%d", &t);

        while (t--) solve();

        return 0;
    }
};

int main() {
    return XenonWZH::main();
}