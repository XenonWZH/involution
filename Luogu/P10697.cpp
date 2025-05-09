#include <bits/stdc++.h>

namespace XenonWZH {
typedef long long ll;

ll pow(ll a, ll b) {
    ll ans = 1;
    for (; b; b >>= 1, a *= a) if (b & 1) ans *= a;
    return ans;
}

void solve() {
    ll n, x;
    scanf("%lld %lld", &n, &x);

    ll dig = 0;
    std::deque<int> q;
    while (n) q.push_front(n % 10), n /= 10, dig++;

    ll ans = 0;
    while (!q.empty()) {
        dig--;
        int k = q.front();
        q.pop_front();
        if (k > x) ans += (k - 1) * pow(9, dig);
        else ans += k * pow(9, dig);
    }

    printf("%lld\n", ans + 1);
}

int main() {
    int t;
    scanf("%d", &t);

    while (t--) solve();

    return 0;
}
};

int main() { return XenonWZH::main(); }