#include <bits/stdc++.h>

namespace XenonWZH {
    void solve() {
        int n;
        scanf("%d", &n);

        std::vector<int> a(n);
        for (int i = 0; i < n; i++) scanf("%d", &a[i]);

        bool flag = false;
        for (int i = 1; i < n; i++) {
            if (a[i] < a[i - 1]) {
                if (flag) {
                    puts("NO");
                    return;
                }
            } else if (a[i] > a[i - 1]) flag = true;
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