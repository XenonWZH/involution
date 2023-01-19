#include <bits/stdc++.h>

namespace XenonWZH {
    void solve() {
        int n, x;
        scanf("%d %d", &n, &x);

        if (n % x == 0) {
            std::vector<int> a(n + 1);
            a[1] = x, a[n] = 1;
            for (int i = 2; i < n; i++) a[i] = i == x ? n : i;
            int pos = x;
            for (int i = pos + 1; i < n; i++) {
                if (i % pos == 0 && n % i == 0) {
                    std::swap(a[pos], a[i]);
                    pos = i;
                }
            }

            for (int i = 1; i <= n; i++) printf("%d ", a[i]);
            putchar('\n');
        } else puts("-1");
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