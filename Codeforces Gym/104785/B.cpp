#include <bits/stdc++.h>
#include <cmath>

namespace XenonWZH {
int main() {
    int n, m, k;
    scanf("%d %d %d", &n, &m, &k);

    std::map<int, int> mp;
    std::vector<long long> ans(m + 1);
    while (k--) {
        int p, c;
        scanf("%d %d", &p, &c);

        if (mp[c]) {
            if (mp[c] == p) ans[c] += 100;
            else ans[c] += std::abs(p - mp[c]);
            mp[c] = 0;
        } else mp[c] = p;
    }

    for (auto [c, p] : mp) {
        if (p) {
            ans[c] += 100;
        }
    }

    for (int i = 1; i <= m; i++) printf("%lld ", ans[i]);
    puts("");

    return 0;
}
}

int main() {
    return XenonWZH::main();
}