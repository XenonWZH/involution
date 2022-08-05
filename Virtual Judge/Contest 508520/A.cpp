#include <cstdio>

const int MAXN = 1250;

int main() {
    int n;

    scanf("%d", &n);
    n /= 2;

    static double f[MAXN + 1][MAXN + 1];
    f[0][0] = f[0][1] = f[1][0] = f[1][1] = 0;
    for (int i = 2; i <= n; i++) f[0][i] = f[i][0] = 1;

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            f[i][j] = (f[i - 1][j] + f[i][j - 1]) / 2;
        }
    }

    printf("%.4f\n", f[n][n]);

    return 0;
}