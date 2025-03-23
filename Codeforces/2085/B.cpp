#include <bits/stdc++.h>

void solve() {
    int n;
    scanf("%d", &n);

    std::vector<int> a(n + 1);
    for (int i = 1; i <= n; i++) scanf("%d", &a[i]);

    std::vector<std::pair<int, int>> ans;

    int remain = 0;
    if (a[n] == 0) {
        a[n - 1] = 1;
        ans.emplace_back(n - 1, n);
        n--;
        remain = 1;
    }

    for (int i = 1; i <= n; i++) {
        if (a[i] == 0) {
            ans.emplace_back(i, i + 1);
            i++;
            continue;
        }
    }


    printf("%d\n", ans.size() + 1);
    int cnt = 0;
    for (auto [u, v] : ans) {
        printf("%d %d\n", u - cnt + (ans[0].second == n + 1 && v != n + 1), v - cnt + (ans[0].second == n + 1 && v != n + 1));
        cnt++;
    }
    printf("%d %d\n", 1, n - cnt + remain);
}

int main() {
    int t;
    scanf("%d", &t);

    while (t--) solve();

    return 0;
}