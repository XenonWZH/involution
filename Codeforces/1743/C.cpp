#include <bits/stdc++.h>

const int MAXN = 2e5;

void solve() {
    int n;
    scanf("%d", &n);

    static char s[MAXN + 2];
    scanf("%s", s + 1);
    s[0] = s[n + 1] = '0';

    std::vector<int> a(n + 2);
    for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
    a[0] = a[n + 1] = 0;
    n++;

    std::vector<std::pair<int, int>> one;
    int l = -1;
    for (int i = 1; i <= n; i++) {
        if (s[i] == '1') {
            if (l == -1) {
                l = std::max(i - 1, 0);
            }
        } else {
            if (l != -1) {
                one.push_back(std::make_pair(l, i - 1));
                l = -1;
            }
        }
    }

    int ans = 0;
    for (auto each : one) {
        int min = INT_MAX;
        for (int i = each.first; i <= each.second; i++) {
            ans += a[i];
            min = std::min(a[i], min);
        }
        ans -= min;
    }

    printf("%d\n", ans);
}

int main() {
    int t;

    scanf("%d", &t);

    while (t--) solve();

    return 0;
}