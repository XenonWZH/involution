#include <bits/stdc++.h>

namespace XenonWZH {
    void solve() {
        int n;
        scanf("%d", &n);

        if (n & 1) {
            for (int i = 0; i < n; i++) printf("1 ");
            putchar('\n');
        } else {
            printf("1 3 ");
            for (int i = 2; i < n; i++) printf("2 ");
            putchar('\n');
        }
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