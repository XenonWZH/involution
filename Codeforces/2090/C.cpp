#include <bits/stdc++.h>

void solve() {
    int n;
    scanf("%d", &n);

    int m = std::ceil(sqrt(2 * n + 1));
    std::vector<std::vector<int>> vis(m + 1, std::vector<int>(m + 1, 4));

    int x0 = 0, y0 = 0, x1 = 1, y1 = 1;

    auto vaild = [&](int x, int y) -> bool {
        if (x - 3 * (x / 3) == 0 || y - 3 * (y / 3) == 0) return false;
        if (x - 3 * (x / 3) == 1 && y - 3 * (y / 3) == 1 && vis[x / 3][y / 3] == 4) return true;
        if (x - 3 * (x / 3) == 1 && y - 3 * (y / 3) == 2 && vis[x / 3][y / 3] == 3) return true;
        if (y / 3 > 0 && x - 3 * (x / 3) == 2 && y - 3 * (y / 3) == 1 && vis[x / 3][y / 3 - 1] == 1) return true;
        if (x - 3 * (x / 3) == 2 && y - 3 * (y / 3) == 1 && vis[x / 3][y / 3] == 2) return true;
        return false;
    };

    for (int i = 1; i <= n; i++) {
        int a;
        scanf("%d", &a);

        if (a == 0) {
            while (vis[x0][y0] != 4) {
                if (y0 == 0) {
                    y0 = x0 + 1;
                    x0 = 0;
                } else x0++, y0--;
            }
            printf("%d %d\n", 3 * x0 + 1, 3 * y0 + 1);
            vis[x0][y0]--;
        } else {
            while (!vaild(x1, y1)) {
                if (y1 == 1) {
                    y1 = x1 + 1;
                    x1 = 1;
                } else x1++, y1--;
            }
            if (y1 / 3 > 0 && x1 - 3 * (x1 / 3) == 2 && y1 - 3 * (y1 / 3) == 1 && vis[x1 / 3][y1 / 3 - 1] == 1) {
                printf("%d %d\n", x1, y1 - 2);
                vis[x1 / 3][y1 / 3 - 1]--;
            } else {
                printf("%d %d\n", x1, y1);
                vis[x1 / 3][y1 / 3]--;
            }
        }
    }
}

int main() {
    int t;
    scanf("%d", &t);

    while (t--) solve();

    return 0;
}