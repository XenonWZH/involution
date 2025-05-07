#include <bits/stdc++.h>

namespace XenonWZH {
typedef long long ll;

void solve() {
    int n, m;
    scanf("%d %d", &n, &m);

    if (m <= 30 && (1ll << m) <= n) {
        puts("-1");
        return;
    }

    auto calc = [&](int mid) -> bool {
        int dig = 0, t = mid;
        while (t) t >>= 1, dig++;
        if ((1 << dig) == mid) dig--;
        if ((1ll << dig) - 1 + 1ll * mid * (m - dig) >= n) return true;
        else return false;
    };

    int l = 1, r = n;
    while (l < r) {
        int mid = (l + r) / 2;
        if (calc(mid)) r = mid;
        else l = mid + 1;
    }

    printf("%d\n", l);
}

int main() {
    int t;
    scanf("%d", &t);

    while (t--) solve();

    return 0;
}
};

int main() { return XenonWZH::main(); }