#include <bits/stdc++.h>

namespace XenonWZH {
typedef long long ll;

const int MAXN = 1e5;
const int MOD = 998244353;

void solve() {
    int n, m, k;
    scanf("%d %d %d", &n, &m, &k);

    int cnt1 = 0, base = 0;
    for (int i = 1; i <= n; i++) {
        printf("%d ", base + cnt1++);
        if (cnt1 == std::max(k, n / (m + 1))) {
            cnt1 = 0;
        }
    }

    puts("");
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    int t;
    scanf("%d", &t);

    while (t--) solve();

    return 0;
}
};

int main() { return XenonWZH::main(); }