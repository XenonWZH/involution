#include <cstdio>
#include <cstring>
#include <algorithm>

const int MAXK = 100;
const int MAXN = 15;

int main() {
    int k, n;
    static int p[MAXN], s[MAXN];
    memset(s, 0, sizeof(s));

    scanf("%d %d", &k, &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &p[i]);
        int x;
        while (scanf("%d", &x) != EOF && x != 0) {
            s[i] |= 1 << (x - 1);
        }
    }

    static double f[MAXK + 1][1 << MAXN];
    for (int i = k - 1; i >= 0; i--) {
        for (int j = 0; j < (1 << n); j++) {
            f[i][j] = 0;
            for (int k = 0; k < n; k++) {
                if ((j | s[k]) == j) f[i][j] += std::max((f[i + 1][1 << k | j] + p[k]) / n, f[i + 1][j] / n);
                else f[i][j] += f[i + 1][j] / n;
            }
        }
    }

    printf("%.6f", f[0][0]);

    return 0;
}