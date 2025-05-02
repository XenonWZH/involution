#include <bits/stdc++.h>

namespace XenonWZH {
typedef long long ll;

void solve() {
    int n;
    scanf("%d", &n);

    std::vector<int> a(n + 1);
    for (int i = 1; i <= n; i++) scanf("%d", &a[i]);

    int ans = 1, p = a[1];
    bool down = false;
    for (int i = 2; i <= n; i++) {
        if (down) {
            if (p < a[i]) {
                ans++;
                down = false;
            }
        } else {
            if (p > a[i]) down = true;
        }
        p = a[i];
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

int main() { return XenonWZH::main(); }