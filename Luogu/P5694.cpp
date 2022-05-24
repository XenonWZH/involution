#include <cstdio>
#include <cstring>

const int MAXL = 10, MAXD = 30, MOD = 11380;

int main() {
    int l1, l2, l3, d;

    scanf("%d %d %d %d", &l1, &l2, &l3, &d);

    static int f[MAXD + 1][MAXL + 1][MAXL + 1][MAXL + 1];
    memset(f, 0, sizeof(f));
    for (int i = 0; i <= d; i++) f[i][0][0][0] = 1;

    for (int i = 1; i <= d; i++) {
        for (int j = 0; j <= l1; j++) {
            for (int k = 0; k <= l2; k++) {
                for (int l = 0; l <= l3; l++) {
                    if (j > 0) {
                        for (int m = 1; m <= j; m++) {
                            for (int n = 0; n <= k; n++) {
                                for (int r = 0; r <= l; r++) {
                                    f[i][j][k][l] = (f[i][j][k][l] + f[i - 1][m - 1][n][r] * f[i][j - m][k - n][l - r]) % MOD;
                                }
                            }
                        }
                    }

                    if (k > 0) {
                        for (int m = 1; m <= k; m++) {
                            for (int n = 0; n <= l; n++) {
                                f[i][j][k][l] = (f[i][j][k][l] + f[i - 1][0][m - 1][n] * f[i][j][k - m][l - n]) % MOD;
                            }
                        }
                    }

                    if (l > 0) {
                        for (int m = 1; m <= l; m++) {
                            f[i][j][k][l] = (f[i][j][k][l] + f[i - 1][0][0][m - 1] * f[i][j][k][l - m]) % MOD;
                        }
                    }
                }
            }
        }
    }

    printf("%d\n", (f[d][l1][l2][l3] - (d ? f[d - 1][l1][l2][l3] : 0) + MOD) % MOD);

    return 0;
}
