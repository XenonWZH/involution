#include <bits/stdc++.h>

typedef long long ll;

int main() {
    int n;
    scanf("%d", &n);

    std::vector<int> a(n + 1), b(n + 1), c(n + 1);
    for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
    for (int i = 1; i <= n; i++) scanf("%d", &b[i]);
    for (int i = 1; i <= n; i++) scanf("%d", &c[i]);
    std::sort(a.begin() + 1, a.end());
    std::sort(b.begin() + 1, b.end());
    std::sort(c.begin() + 1, c.end());

    std::vector<ll> cntb(n + 1);
    int p = n;
    for (int i = n; i >= 1; i--) {
        if (i < n) cntb[i] += cntb[i + 1];
        while (p && c[p] > b[i]) cntb[i]++, p--;
    }

    std::vector<ll> cnta(n + 1);
    p = n;
    for (int i = n; i >= 1; i--) {
        if (i < n) cnta[i] += cnta[i + 1];
        while (p && b[p] > a[i]) cnta[i] += cntb[p], p--;
    }

    ll ans = 0;
    for (int i = 1; i <= n; i++) ans += cnta[i];
    printf("%lld\n", ans);

    return 0;
}