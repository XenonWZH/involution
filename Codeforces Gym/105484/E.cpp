#include <bits/stdc++.h>

void solve() {
    int n, k;
    std::cin >> n >> k;
    k = std::min(n - 1, k);

    std::string s;
    std::cin >> s;

    if (n < 7) {
        std::cout << "0\n";
        return;
    }

    std::string t = s + s;

    int m = t.length();
    std::vector<int> ans(m);
    for (int i = 0; i < m - 6; i++) {
        if (i != 0) ans[i] = ans[i - 1];
        if (t[i] == 'n' && t[i + 1] == 'a' && t[i + 2] == 'n' && t[i + 3] == 'j' && t[i + 4] == 'i' && t[i + 5] == 'n' && t[i + 6] == 'g') ans[i]++;
    }
    for (int i = m - 6; i < m; i++) ans[i] = ans[i - 1];

    int maxn = 0;
    for (int i = 0; i <= k; i++) maxn = std::max(maxn, ans[i + n - 7] - (i == 0 ? 0 : ans[i - 1]));

    std::cout << maxn << "\n";
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    int t;
    std::cin >> t;

    while (t--) solve();

    return 0;
}