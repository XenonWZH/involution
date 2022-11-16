#include <iostream>
#include <vector>

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    int t;

    std::cin >> t;

    while (t--) {
        int n;
        std::cin >> n;

        std::string s;
        std::cin >> s;

        std::vector<int> a(n);
        for (int i = 0; i < n; i++) a[i] = s[i] - '0';

        int ans = 0;
        for (int i = 0; i < n; i++) {
            int tot = 0, max = 0;
            std::vector<int> cnt(10, 0);
            for (int j = i; j < std::min(n, i + 100); j++) {
                cnt[a[j]]++;
                if (cnt[a[j]] == 1) tot++;
                max = std::max(cnt[a[j]], max);
                if (max <= tot) ans++;
            }
        }

        std::cout << ans << std::endl;
    }

    return 0;
}