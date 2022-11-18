#include <bits/stdc++.h>

namespace XenonWZH {
    void solve() {
        long long l, r, x, a, b;
        scanf("%lld %lld %lld", &l, &r, &x);
        scanf("%lld %lld", &a, &b);
        if (a > b) std::swap(a, b);

        if (a == b) puts("0");
        else if (b - a >= x) puts("1");
        else if (r - b >= x || a - l >= x) puts("2");
        else if (r - a >= x && b - l >= x) puts("3");
        else puts("-1");
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