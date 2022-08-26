#include <cstdio>
#include <cmath>
#include <algorithm>

const int MAXN = 5000;

int main() {
    int r, b;

    scanf("%d %d", &r, &b);

    static double f[MAXN + 1];
    for (int i = 0; i <= b; i++) f[i] = 0;

    for (int i = 1; i <= r; i++) {
        f[0] = i;
        for (int j = 1; j <= b; j++) {
            f[j] = std::max(0.0, (i * (f[j] + 1) + j * (f[j - 1] - 1)) / (i + j));
        }
    }

    printf("%.6f\n", floor(f[b] * 1e6) / 1e6);

    return 0;
}
