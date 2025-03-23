#include <bits/stdc++.h>

void solve() {
    int n, m;
    std::cin >> n >> m;

    std::vector<std::vector<int>> a(n + 1, std::vector<int>(m + 1));
    for (int i = 1; i <= n; i++) {
        std::string s;
        std::cin >> s;
        for (int j = 0; j < m; j++) a[i][j + 1] = s[j] - '0';
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (a[i][j] == 0) break;
            a[i][j] = 2;
        }
    }

    for (int j = 1; j <= m; j++) {
        for (int i = 1; i <= n; i++) {
            if (a[i][j] == 0) break;
            a[i][j] = 2;
        }
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (a[i][j] == 1)  {
                std::cout << "NO\n";
                return;
            }
        }
    }

    std::cout << "YES\n";
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