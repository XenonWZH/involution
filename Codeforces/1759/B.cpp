#include <bits/stdc++.h>

namespace XenonWZH {
    void solve() {
        int m, s;
        scanf("%d %d", &m, &s);

        std::vector<int> a(m);
        for (int i = 0; i < m; i++) scanf("%d", &a[i]);
        for (int i = 0; i < m; i++) s += a[i];

        double n = (sqrt(8 * s + 1) - 1) / 2;
        if (n != floor(n)) {
            puts("NO");
            return;
        }

        for (int i = 0; i < m; i++) {
            if (a[i] > n) {
                puts("NO");
                return;
            }
        }

        std::vector<bool> vis(51, false);
        for (int i = 0; i < m; i++) {
            if (vis[a[i]]) {
                puts("NO");
                return;
            }
            vis[a[i]] = true;
        }

        puts("YES");
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