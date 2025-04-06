#include <bits/stdc++.h>

namespace XenonWZH {
typedef long long ll;

const int MAXN = 1e5;
const int MOD = 998244353;

void solve() {
    int n;
    scanf("%d", &n);

    if (n % 2 == 0) {
        puts("-1");
        return;
    }

    printf("%d ", n);
    for (int i = 1; i <= n - 1; i++) printf("%d ", i);
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