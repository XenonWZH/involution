#include <cstdio>
#include <algorithm>

const int MAXN = 15;
const int MAXK = 100;

int main() {
    int k, n;
    static double score[MAXN + 1];
    static int bef[MAXN + 1];

    scanf("%d %d", &k, &n);
    for (int i = 1; i <= n; i++) {
        int x;
        scanf("%lf", &score[i]);
        while (scanf("%d", &x) != EOF) {
            if (x == 0) break;
            bef[i] |= (1 << (x - 1));
        }
    }

    static double f[MAXK + 2][1 << MAXN];
    for (int i = k; i >= 1; i--) {
        for (int j = 0; j < (1 << n); j++) {
            for (int l = 1; l <= n; l++) {
                if ((bef[l] | j) == j) f[i][j] += std::max(f[i + 1][j | (1 << (l - 1))] + score[l], f[i + 1][j]);
                else f[i][j] += f[i + 1][j];
            }
            f[i][j] *= 1.0 / n;
        }
    }

    printf("%.6f\n", f[1][0]);

    return 0;
}