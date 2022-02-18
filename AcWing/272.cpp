#include <cstdio>
#include <cstring>
#include <iostream>

const int MAXN = 3000;

int main() {
    int n;
    static int a[MAXN + 1], b[MAXN + 1];

    std::cin >> n;
    for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
    for (int i = 1; i <= n; i++) scanf("%d", &b[i]);

    static int f[MAXN + 1][MAXN + 1];
    memset(f, 0, sizeof(f));

    for (int i = 1; i <= n; i++) {
        int val = 0;
        if (b[0] < a[i]) val = f[i - 1][0];
        for (int j = 1; j <= n; j++) {
            if (a[i] == b[j]) f[i][j] = val + 1;
            else f[i][j] = f[i - 1][j];
            if (b[j] < a[i]) val = std::max(val, f[i - 1][j]);
        }
    }

    int ans = 0;
    for (int i = 1; i <= n; i++) ans = std::max(ans, f[n][i]);

    std::cout << ans << std::endl;

    return 0;
}