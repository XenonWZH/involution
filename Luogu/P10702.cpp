#include <bits/stdc++.h>

namespace XenonWZH {
typedef long long ll;

void solve() {
    ll x;
    scanf("%lld", &x);

    for (int i = 1;; i++) {
        if (x % i != 0) {
            printf("%d\n", i);
            break;
        }
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