#include <cstdio>
#include <cstring>
#include <iostream>

const int MAXN = 1000;

int main() {
    int t;

    std::cin >> t;

    while (t--) {
        int p, q;

        std::cin >> p >> q;

        static int cnt[MAXN + 1];
        memset(cnt, 0, sizeof(cnt));
        for (int i = 0, x, y; i < q; i++) {
            scanf("%d%d", &x, &y);
            cnt[x]++, cnt[y]++;
        }

        int ans = 0;
        for (int i = 1; i <= p; i++) {
            if (cnt[i] % 2 == 1) {
                ans++;
            }
        }

        std::cout << (ans == 0 || ans == 2 ? "YES" : "NO") << std::endl;
    }

    return 0;
}