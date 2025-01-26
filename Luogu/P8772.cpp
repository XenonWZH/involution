#include <bits/stdc++.h>

typedef long long ll;

int main() {
    int n;
    scanf("%d", &n);

    std::vector<ll> a(n + 1);
    for (int i = 1; i <= n; i++) scanf("%lld", &a[i]);

    std::vector<ll> s(n + 1);
    for (int i = 1; i <= n; i++) s[i] = s[i - 1] + a[i];

    ll ans = 0;
    for (int i = 1; i <= n - 1; i++) ans += a[i] * (s[n] - s[i]);

    printf("%lld\n", ans);

    return 0;
}