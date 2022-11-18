#include <bits/stdc++.h>

namespace XenonWZH {
    void solve() {
        int n, p;
        scanf("%d %d", &n, &p);

        std::vector<int> a(n);
        for (int i = 0; i < n; i++) scanf("%d", &a[i]);

        std::map<int, bool> mp;
        for (int i = 0; i < n; i++) mp[a[i]] = true;
        int l = -1, r = p;
        for (int i = 0; i < p; i++) {
            if (mp[i]) l++;
            else break;
        }
        for (int i = p - 1; i >= 0; i--) {
            if (mp[i]) r--;
            else break;
        }
        if (l >= r) {
            puts("0");
            return;
        }

        if (a[n - 1] <= l) {
            printf("%d\n", r - a[n - 1] - 1);
            return;
        }
        long long bef = p - a[n - 1];
        r = a[n - 1];

        a[n - 1] = p;
        for (int i = n - 1; i >= 0; i--) {
            if (a[i] >= p) {
                a[i] = 0;
                if (i == 0) mp[1] = true;
                else a[i - 1]++;
            }
            mp[a[i]] = true;
        }

        while (r > 0 && mp[r]) r--;

        printf("%lld\n", bef + r);
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