#include <bits/stdc++.h>

namespace XenonWZH {
void solve() {
    long long n;

    scanf("%lld", &n);

    std::vector<int> bit;
    for (int i = 0; (1ll << i) <= n; i++) if ((n >> i) & 1) bit.push_back(i);

    int k = bit.size();

    if (k == 1) {
        printf("1\n%d\n", n);
        return;
    }

    k++;
    printf("%d\n", k);

    if (n > 1) for (int i = k - 2; i >= 0; i--) printf("%lld ", n ^ (1ll << bit[i]));
    printf("%lld\n", n);
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