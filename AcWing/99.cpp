// 99. 激光炸弹
// WzhDnwzWzh

#include <cstring>
#include <iostream>

const int MAXN = 5000;

int main() {
    int n, r;
    static short w[MAXN + 1][MAXN + 1];
    memset(w, 0, sizeof(w));
    std::cin >> n >> r;

    for (int i = 0, x, y, wInput; i < n; i++) {
        std::cin >> x >> y >> wInput;
        w[x + 1][y + 1] += wInput;
    }

    static short s[MAXN + 1][MAXN + 1];
    int ans = 1;
    memset(s, 0, sizeof(s));

    for (int i = 1; i <= MAXN; i++) {
        for (int j = 1; j <= MAXN; j++) {
            int x = i - r > 0 ? i - r : 0;
            int y = j - r > 0 ? j - r : 0;
            s[i][j] = w[i][j] - w[i][y] - w[x][j] + w[x][y] + s[i - 1][j] + s[i][j - 1] - s[i - 1][j - 1];
            if (s[i][j] > ans) ans = s[i][j];
        }
    }

    std::cout << ans << std::endl;

    return 0;
}