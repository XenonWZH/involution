#include <bits/stdc++.h>

namespace XenonWZH {
typedef long long ll;

const int MAXN = 1e5;
const int MOD = 998244353;

void solve() {
    int a, b, c, d;
    scanf("%d %d %d %d", &a, &b, &c, &d);

    puts(std::min(b, d) <= std::min(a, c) ? "Gellyfish" : "Flower");
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