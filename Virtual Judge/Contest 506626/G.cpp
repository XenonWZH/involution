#include <cstdio>
#include <cmath>
#include <cstring>
#include <algorithm>

const int MAXN = 20;
const double EPS = 1e-6;

inline void solve() {
    int n, m;
    static double x[MAXN], y[MAXN];

    scanf("%d %d", &n, &m);
    for (int i = 0; i < n; i++) {
        scanf("%lf %lf", &x[i], &y[i]);
    }

    if (n == 1) {
        puts("1");
        return;
    }

    static int g[MAXN * MAXN];
    memset(g, 0, sizeof(g));
    int sizeG = 0;
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (fabs(x[j] - x[i]) < EPS) continue;
            double a = (x[i] * y[j] - x[j] * y[i]) / (x[i] * x[j] * x[j] - x[i] * x[i] * x[j]);
            double b = (x[i] * x[i] * y[j] - x[j] * x[j] * y[i]) / (x[i] * x[i] * x[j] - x[i] * x[j] * x[j]);
            if (a > -EPS) continue;

            for (int k = 0; k < n; k++) {
                if (fabs(a * x[k] * x[k] + b * x[k] - y[k]) < EPS) {
                    g[sizeG] |= (1 << k);
                }
            }
            sizeG++;
        }
    }

    static int f[1 << MAXN];
    memset(f, 0x3f, sizeof(f));
    for (int i = 0; i < n; i++) f[1 << i] = 1;
    f[0] = 0;

    for (int i = 0; i < (1 << n); i++) {
        for (int j = 0; j < sizeG; j++) {
            f[i | g[j]] = std::min(f[i | g[j]], f[i] + 1);
        }
        for (int j = 0; j < n; j++) {
            f[i | (1 << j)] = std::min(f[i | (1 << j)], f[i] + 1);
        }
    }

    printf("%d\n", f[(1 << n) - 1]);
}

int main() {
    int t;

    scanf("%d", &t);

    while (t--) solve();

    return 0;
}