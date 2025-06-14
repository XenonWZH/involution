#include <bits/stdc++.h>

namespace XenonWZH {
typedef long long ll;

const int MAXN = 1e5;
const int MOD = 998244353;

ll gcd(ll a, ll b) { return b == 0 ? a : gcd(b, a % b); }

ll pow(ll a, ll b) {
    ll ans = 1 % MOD;
    for (; b; b >>= 1, a = a * a % MOD) if (b & 1) ans = ans * a % MOD;
    return ans;
}

void solve() {
    int n, k;
    scanf("%d %d", &n, &k);

    for (int i = 0; i < k; i++) putchar('1');
    for (int i = 0; i < n - k; i++) putchar('0');
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