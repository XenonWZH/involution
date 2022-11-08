#include <bits/stdc++.h>

namespace XenonWZH {
    int main() {
        freopen("count.in", "r", stdin);
        freopen("count.out", "w", stdout);

        int n, s;
        scanf("%d %d", &n, &s);

        std::vector<int> a(n);
        for (int i = 0; i < n; i++) scanf("%d", &a[i]);
        std::sort(a.begin(), a.end());

        long long ans = 0;
        for (int i = 0; i < n; i++) ans += a.end() - std::upper_bound(a.begin() + i + 1, a.end(), s - a[i]);

        printf("%lld\n", ans);

        fclose(stdin);
        fclose(stdout);

        return 0;
    }
}

int main() {
    return XenonWZH::main();
}