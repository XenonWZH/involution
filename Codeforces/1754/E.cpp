#include <bits/stdc++.h>

const int MOD = 998244353;

inline long long pow(const int n, const int k) {
    long long ans = 1;
    for (long long num = n, t = k; t; num = num * num % MOD, t >>= 1) {
        if (t & 1) {
            ans = ans * num % MOD;
        }
    }
    return ans;
}

void solve() {
    int n;
    scanf("%d", &n);

    std::vector<int> a(n);
    for (int i = 0; i < n; i++) scanf("%d", &a[i]);

    int cnt = 0, now = 0;
    for (int i = 0; i < n; i++) if (a[i] == 0) cnt++;
    for (int i = 0; i < cnt; i++) if (a[i] == 0) now++;

    std::vector<long long> f(cnt + 1);
    f[cnt] = 0;

    for (int i = cnt - 1; i >= 0; i--) {
        f[i] = (f[i + 1] + (1ll * n * (n - 1) % MOD * pow(2, MOD - 2) % MOD * pow(cnt - i, MOD - 2) % MOD * pow(cnt - i, MOD - 2) % MOD)) % MOD;
    }

    printf("%lld\n", f[now]);
}

int main() {
    int t;

    scanf("%d", &t);

    while (t--) solve();

    return 0;
}