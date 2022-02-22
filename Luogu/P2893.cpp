#include <cstdio>
#include <cstring>
#include <cmath>
#include <iostream>
#include <algorithm>

const int MAXN = 2000, INF = 0x3f3f3f3f;

int main() {
    int n;
    static int a[MAXN + 1];

    std::cin >> n;
    for (int i = 1; i <= n; i++) scanf("%d", &a[i]);

    static int fG[MAXN + 1][MAXN + 1], s[MAXN + 1];
    memset(fG, 0x3f, sizeof(fG));
    memcpy(s, a, sizeof(a));
    std::sort(s + 1, s + n + 1);
    for (int i = 1; i <= n; i++) fG[0][i] = 0;

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            fG[i][0] = std::min(fG[i][0], fG[i - 1][j]);
            fG[i][j] = fG[i][0] + abs(a[i] - s[j]);
        }
    }

    static int fL[MAXN + 1][MAXN + 1];
    memset(fL, 0x3f, sizeof(fG));
    memcpy(s, a, sizeof(a));
    std::sort(s + 1, s + n + 1);
    for (int i = 1; i <= n; i++) fL[0][i] = 0;

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            fL[i][0] = std::min(fL[i][0], fL[i - 1][j]);
            fL[i][j] = fL[i][0] + abs(a[i] - s[j]);
        }
    }

    int ans = INF;
    for (int i = 1; i <= n; i++) {
        if (fG[n][i] < ans) ans = fG[n][i];
        if (fL[n][i] < ans) ans = fL[n][i];
    }

    std::cout << ans << std::endl;

    return 0;
}