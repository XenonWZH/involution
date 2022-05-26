#include <cstdio>

const int MAXN = 10000;

int main() {
    double n;

    scanf("%lf", &n);

    static double f[MAXN + 1], g[MAXN + 1];
    for (int i = n - 1; i >= 0; i--) f[i] = f[i + 1] + n / (n - i);
    for (int i = n - 1; i >= 0; i--) g[i] = (((n - i) / n) * (g[i + 1] + f[i + 1]) + (i / n) * f[i] + 1) / (1 - i / n);

    printf("%.2f\n", g[0]);

    return 0;
}