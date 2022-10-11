#include <bits/stdc++.h>

void solve() {
    int n;
    scanf("%d", &n);

    std::vector<int> p(n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &p[i]);
        p[i]--;
    }

    long long ans = 0;
    for (int i = std::round(log(n) / log(2)) - 1; i >= 0; i--) {
        std::vector<bool> vis(n);

        int res = (1 << i);
        for (int j = 0; j < n / res; j++) {
            if (vis[p[j * res] / res]) {
                puts("-1");
                return;
            } else vis[p[j * res] / res] = true;
            for (int k = j * res + 1; k < (j + 1) * res; k++) {
                if (p[j * res] / res != p[k] / res) {
                    puts("-1");
                    return;
                }
            }
            if ((j & 1) && p[(j - 1) * res] / res > p[j * res] / res) ans++;
        }
    }

    printf("%lld\n", ans);
}

int main() {
    int t;

    scanf("%d", &t);

    while (t--) solve();

    return 0;
}