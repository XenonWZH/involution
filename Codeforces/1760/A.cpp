#include <bits/stdc++.h>

namespace XenonWZH {
    void solve() {
        std::vector<int> a(3);
        scanf("%d %d %d", &a[0], &a[1], &a[2]);
        std::sort(a.begin(), a.end());
        printf("%d\n", a[1]);
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