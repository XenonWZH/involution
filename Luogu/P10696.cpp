#include <bits/stdc++.h>

namespace XenonWZH {
typedef long long ll;

const int MAXN = 1e5;
const int MOD = 998244353;

void solve() {
    int n;
    scanf("%d", &n);

    std::vector<int> a(n + 1);
    for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
    std::sort(a.begin() + 1, a.end());

    printf("%d\n", a.back());
}

int main() {
    int t;
    scanf("%d", &t);

    while (t--) solve();

    return 0;
}
};

int main() { return XenonWZH::main(); }