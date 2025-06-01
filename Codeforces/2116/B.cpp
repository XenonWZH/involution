#include <bits/stdc++.h>

namespace XenonWZH {
typedef long long ll;

const int MAXN = 1e5;
const int MOD = 998244353;

ll pow(ll a, ll b) {
    ll ans = 1;
    for (; b; b >>= 1, a = a * a % MOD) if (b & 1) ans = ans * a % MOD;
    return ans;
}

void solve() {
    int n;
    scanf("%d", &n);

    std::vector<ll> a(n), b(n);
    for (int i = 0; i < n; i++) scanf("%lld", &a[i]);
    for (int i = 0; i < n; i++) scanf("%lld", &b[i]);

    int t = 0, l = 0;
    for (int i = 0; i < n; i++) {
        if (a[i] > a[t]) t = i;
        if (b[i] > b[l]) l = i;
        if (a[t] > b[l]) printf("%lld ", (pow(2, a[t]) + pow(2, b[i - t])) % MOD);
        else if (a[t] < b[l]) printf("%lld ", (pow(2, b[l]) + pow(2, a[i - l])) % MOD);
        else printf("%lld ", (pow(2, a[t]) + pow(2, std::max(b[i - t], a[i - l]))) % MOD);
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