#include <bits/stdc++.h>

namespace XenonWZH {
void solve() {
    int n, k;

    scanf("%d %d", &n, &k);

    int ans = 0;
    while (n > 1) {
        n -= k - 1;
        ans++;
    }

    printf("%d\n", ans);
}

int main() {
    int t;

    scanf("%d", &t);

    while (t--) solve();

    return 0;
}
};

int main() {
    return XenonWZH::main();
}