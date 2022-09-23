#include <cstdio>
#include <cmath>
#include <climits>
#include <iostream>
#include <algorithm>

const int MAXN = 300;

inline void solve() {
    int n;
    static int a[MAXN + 1];

    scanf("%d", &n);
    for (int i = 1; i <= n; i++) scanf("%d", &a[i]);

    long long ans = LLONG_MAX;
    for (int i = 1; i <= n; i++) {
        static long long b[MAXN + 1];
        for (int j = 1; j <= n; j++) b[j] = std::abs(a[i] - a[j]);
        std::sort(b + 1, b + n + 1);
        ans = std::min(ans, b[2] + b[3]);
    }

    printf("%lld\n", ans);
}

int main() {
    int t;

    scanf("%d", &t);

    while (t--) solve();

    return 0;
}