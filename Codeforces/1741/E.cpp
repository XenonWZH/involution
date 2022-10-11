#include <bits/stdc++.h>

void solve() {
    int n;
    scanf("%d", &n);
    std::vector<int> a(n + 1);
    for (int i = 1; i <= n; i++) scanf("%d", &a[i]);

    std::vector<std::pair<int, int>> b;
    for (int i = 1; i <= n; i++) {
        if (i - a[i] >= 1) b.push_back(std::make_pair(i - a[i], i));
        if (i + a[i] <= n) b.push_back(std::make_pair(i, i + a[i]));
    }

    std::sort(b.begin(), b.end());

    std::vector<bool> valid(n + 1);
    valid[0] = true;
    for (auto i : b) {
        if (valid[i.first - 1]) {
            valid[i.second] = true;
        }
    }

    if (valid[n]) puts("YES");
    else puts("NO");
}

int main() {
    int t;

    scanf("%d", &t);

    while (t--) solve();

    return 0;
}