#include <cstdio>
#include <climits>
#include <iostream>

const int MAXN = 100;

void solve() {
    int n;
    static int a[MAXN + 1];

    scanf("%d", &n);

    int min = INT_MAX;
    for (int i = 1; i <= n; i++) {
        scanf("%d", &a[i]);
        min = std::min(a[i], min);
    }

    int ans = 0;
    for (int i = 1; i <= n; i++) {
        ans += a[i] / (2 * min - 1);
        if (a[i] % (2 * min - 1) == 0) ans--;
    }

    printf("%d\n", ans);
}

int main() {
    int t;

    scanf("%d", &t);

    while (t--) solve();

    return 0;
}