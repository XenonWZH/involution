#include <bits/stdc++.h>

namespace XenonWZH {
    void solve() {
        int n, a, b;
        scanf("%d %d %d", &n, &a, &b);

        if (a == b && n == a) puts("Yes");
        else if (a + b + 1 >= n) puts("No");
        else puts("Yes");
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