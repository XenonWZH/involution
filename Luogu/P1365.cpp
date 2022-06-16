#include <cstdio>

const int MAXN = 300000;

int main() {
    int n;
    static char str[MAXN + 1];

    scanf("%d", &n);
    scanf("%s", str + 1);

    static double f[MAXN + 1];
    double len;

    for (int i = 1; i <= n; i++) {
        switch (str[i]) {
            case 'x':
                f[i] = f[i - 1];
                len = 0;
                break;
            case 'o':
                f[i] = f[i - 1] + 2 * len + 1;
                len++;
                break;
            case '?':
                f[i] = f[i - 1] + len + 0.5;
                len = (len + 1) / 2;
                break;
        }
    }

    printf("%.4lf\n", f[n]);

    return 0;
}