#include <bits/stdc++.h>

void solve() {
    int n;
    scanf("%d", &n);

    std::vector<long long> a(n), b(n);
    for (int i = 0; i < n; i++) scanf("%lld", &a[i]);
    for (int i = 0; i < n; i++) scanf("%lld", &b[i]);

    int l = 0, r = n - 1;
    long long ans = 0;
    while (l < r) {
        if (b[l] < b[r]) {
            a[l + 1] += b[l];
            ans += a[l];
            l++;
        } else {
            a[r - 1] += b[r];
            ans += a[r];
            r--;
        }
    }

    printf("%lld\n", ans + a[l]);
}

int main() {
    int t;

    scanf("%d", &t);

    while (t--) solve();

    return 0;
}