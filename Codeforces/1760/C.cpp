#include <bits/stdc++.h>

namespace XenonWZH {
    void solve() {
        int n;
        scanf("%d", &n);

        std::vector<std::pair<int, int>> a(n);
        for (int i = 0; i < n; i++) {
            scanf("%d", &a[i].first);
            a[i].second = i;
        }

        std::sort(a.begin(), a.end());

        std::vector<int> b(n);
        for (int i = 0; i < n - 1; i++) b[a[i].second] = a[i].first - a[n - 1].first;
        b[a[n - 1].second] = a[n - 1].first - a[n - 2].first;

        for (int i = 0; i < n; i++) printf("%d ", b[i]);
        putchar('\n');
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