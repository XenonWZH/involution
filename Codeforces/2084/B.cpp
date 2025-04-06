#include <bits/stdc++.h>

namespace XenonWZH {
typedef long long ll;

const int MAXN = 1e5;
const int MOD = 998244353;

ll gcd(ll a, ll b) { return b == 0 ? a : gcd(b, a % b); }

void solve() {
    int n;
    scanf("%d", &n);

    std::vector<ll> a(n + 1);
    for (int i = 1; i <= n; i++) scanf("%lld", &a[i]);

    std::sort(a.begin() + 1, a.end());

    bool con = false;
    ll res;
    for (int i = 2; i <= n; i++) {
        if (a[i] % a[1] == 0) {
            if (con == false) con = true, res = a[i];
            else res = gcd(res, a[i]);
        }
    }

    if (con) puts(res == a[1] ? "Yes" : "No");
    else puts("No");
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