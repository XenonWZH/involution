#include <bits/stdc++.h>

void solve() {
    int n;
    scanf("%d", &n);

    std::vector<int> a(n);
    for (int i = 0; i < n; i++) scanf("%d", &a[i]);

    int ans = INT_MAX;
    for (int i = 0; i < n; i++) {
        int now = 0;
        bool flag = true;
        int sum = 0;
        for (int j = 0; j <= i; j++) sum += a[j];

        int res = 0, cnt = 0;
        for (int j = 0; j < n; j++) {
            res += a[j], cnt++;
            if (res == sum) now = std::max(now, cnt), res = 0, cnt = 0;
            if (res > sum) {
                flag = false;
                break;
            }
        }

        if (flag && res == 0) ans = std::min(ans, now);
    }

    printf("%d\n", ans);
}

int main() {
    int t;

    scanf("%d", &t);

    while (t--) solve();

    return 0;
}