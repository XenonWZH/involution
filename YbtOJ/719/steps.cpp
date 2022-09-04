#include <cstdio>
#include <cstring>
#include <iostream>

const int MAXN = 100;

int main() {
#ifndef DBG
    freopen("steps.in", "r", stdin);
    freopen("steps.out", "w", stdout);
#endif

    int n;
    static int a[MAXN + 1];

    scanf("%d", &n);
    for (int i = 1; i <= n; i++) scanf("%d", &a[i]);

    static int f[MAXN + 1][MAXN + 1][2];
    memset(f, 0xcf, sizeof(f));
    f[0][0][0] = f[0][0][1] = 0;

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= i; j++) {
            if (std::max(f[i - 1][j][0], f[i - 1][j][1]) >= 100) f[i][j][1] = std::max(f[i - 1][j][0], f[i - 1][j][1]) - 100;
            if (std::max(f[i - 1][j - 1][0], f[i - 1][j - 1][1]) + a[i] >= 0) f[i][j][0] = std::max(f[i - 1][j - 1][0], f[i - 1][j - 1][1]) + a[i];
        }
    }

    for (int i = 1; i <= n; i++) {
        if (f[n][i][0] >= 0) {
            printf("%d\n", i);
            return 0;
        }
        if (f[n][i][1] >= 0) {
            printf("%d\n", i);
            return 0;
        }
    }
    puts("-1");

#ifndef DBG
    fclose(stdin);
    fclose(stdout);
#endif

    return 0;
}