#include <bits/stdc++.h>

void solve() {
    int n;
    scanf("%d", &n);

    std::vector<int> a(n);
    for (int i = 0; i < n; i++) scanf("%d", &a[i]);

    if (n & 1) {
        puts("-1");
        return;
    }

    std::vector<std::pair<int, int>> ans;
    for (int i = 0; 2 * i < n; i++) {
        if (a[2 * i] == a[2 * i + 1]) {
            ans.push_back(std::make_pair(2 * i, 2 * i + 1));
        } else {
            ans.push_back(std::make_pair(2 * i, 2 * i));
            ans.push_back(std::make_pair(2 * i + 1, 2 * i + 1));
        }
    }

    printf("%zu\n", ans.size());
    for (auto each : ans) {
        printf("%d %d\n", each.first + 1, each.second + 1);
    }
}

int main() {
    int t;

    scanf("%d", &t);

    while (t--) solve();

    return 0;
}