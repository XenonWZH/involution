#include <bits/stdc++.h>

namespace XenonWZH {
    void solve() {
        int n;
        scanf("%d", &n);

        std::vector<int> a(n + 1);
        for (int i = 1; i <= n; i++) scanf("%d", &a[i]);

        std::vector<long long> s(n + 1);
        for (int i = 1; i <= n; i++) s[i] = s[i - 1] + a[i];

        int max = 1, ans = 0;
        long long begin = 0;
        for (int i = 1; i <= n; i++) {
            if (a[i] == 0) break;
            begin += a[i];
            if (begin == 0) ans++;
        }

        std::map<long long, int> mp;
        for (int i = n; i >= 1; i--) {
            mp[s[i]]++;
            max = std::max(max, mp[s[i]]);

            if (a[i] == 0) {
                ans += max;
                mp.clear();
                max = 1;
            }
        }

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