#include <iostream>
#include <unordered_map>

const int MAXN = 1000;

int main() {
    int t;

    std::cin >> t;

    while (t--) {
        int n;
        static std::string s[4][MAXN + 1];

        std::cin >> n;

        static std::unordered_map<std::string, int> m[4];
        for (int i = 1; i <= 3; i++) {
            m[i].clear();
            for (int j = 1; j <= n; j++) {
                std::cin >> s[i][j];
                m[i][s[i][j]] = 1;
            }
        }

        for (int i = 1; i <= 3; i++) {
            int ans = 0;
            for (int j = 1; j <= n; j++) {
                int cnt = m[1][s[i][j]] + m[2][s[i][j]] + m[3][s[i][j]];
                if (cnt == 1) ans += 3;
                if (cnt == 2) ans += 1;
            }
            printf("%d ", ans);
        }
        putchar('\n');
    }

    return 0;
}