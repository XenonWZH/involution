#include <cstdio>

const int MAXN = 1000;

int n, m, x, y;
double coe[MAXN + 1][MAXN + 2], f[MAXN + 1][MAXN + 2];

void gauses() {
    for (int i = 1; i <= m; i++) {
        double w = 1.0 / coe[i][i];
        coe[i][i] *= w;
        coe[i][m + 1] *= w;
        if (i == m) break;

        coe[i][i + 1] *= w;
        w = coe[i + 1][i] / coe[i][i];
        coe[i + 1][i] -= w * coe[i][i];
        coe[i + 1][i + 1] -= w * coe[i][i + 1];
        coe[i + 1][m + 1] -= w * coe[i][m + 1];
    }

    for (int i = m - 1; i >= 1; i--)coe[i][m + 1] -= coe[i + 1][m + 1] * coe[i][i + 1];
}

int main() {
    scanf("%d %d", &n, &m);
    scanf("%d %d", &x, &y);

    for (int i = n - 1; i >= x; i--) {
        coe[1][1] = coe[m][m] = -2 / 3.0;
        coe[1][2] = coe[m][m - 1] = 1 / 3.0;
        for (int j = 2; j < m; j++) {
            coe[j][m + 1] = -f[i + 1][j] / 4.0 - 1;
            coe[j][j] = -3 / 4.0;
            coe[j][j - 1] = coe[j][j + 1] = 1 / 4.0;
        }
        if (m == 1) coe[1][1] = -1 / 2.0;
        coe[1][m + 1] = -f[i + 1][1] / 3.0 - 1;
        coe[m][m + 1] = -f[i + 1][m] / 3.0 - 1;
        if (m == 1) coe[m][m + 1] = -f[i + 1][m] / 2.0 - 1;
        gauses();
        for (int j = 1; j <= m; j++) f[i][j] = coe[j][m + 1];
    }

    printf("%.10f\n", f[x][y]);

    return 0;
}