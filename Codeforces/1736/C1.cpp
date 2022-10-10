#include <bits/stdc++.h>

void solve() {
    int n;
    scanf("%d", &n);

    std::vector<int> a(n);
    for (int i = 0; i < n; i++) scanf("%d", &a[i]);

    long long ans = 0;
    int cnt = 0;
    for (int i = 0; i < n; i++) {
        cnt = std::min(cnt + 1, a[i]);
        ans += cnt;
    }

    printf("%lld\n", ans);
}

int main() {
    int t;

    scanf("%d", &t);

    while (t--) solve();

    return 0;
}