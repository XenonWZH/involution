#include <bits/stdc++.h>

namespace XenonWZH {
typedef long long ll;

int gcd(int a, int b) { return b == 0 ? a : gcd(b, a % b); }

void solve() {
    int n, m;
    scanf("%d %d", &n, &m);

    if (gcd(n, m) != 1) puts("No");
    else {
        puts("Yes");
        for (int i = 1; i <= n; i++) printf("%lld ", (1ll * i * m + 1) % (1ll * n * m));
        puts("");
        for (int j = 1; j <= m; j++) printf("%lld ", (1ll * j * n + 1) % (1ll * n * m));
        puts("");
    }
}

int main() {
    int t;
    scanf("%d", &t);

    while (t--) solve();

    return 0;
}
};

int main() { return XenonWZH::main(); }