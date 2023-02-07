#include <cstdio>
#include <cmath>
#include <algorithm>

const int MAXN = 100000;
const int LOG_MAXN = 20;

int n, m;
int a[MAXN + 1];
int f[MAXN + 1][LOG_MAXN + 1];

void prepare() {
    for (int i = 1; i <= n; i++) f[i][0] = a[i];
    int t = log(n) / log(2) + 1;
    for (int j = 1; j < t; j++) {
        for (int i = 1; i <= n - (1 << j) + 1; i++) {
            f[i][j] = std::min(f[i][j - 1], f[i + (1 << (j - 1))][j - 1]);
        }
    }
}

int query(int l, int r) {
    int k = log(r - l + 1) / log(2);
    return std::min(f[l][k], f[r - (1 << k) + 1][k]);
}

int main() {
    scanf("%d %d", &n, &m);
    for (int i = 1; i <= n; i++) scanf("%d", &a[i]);

    prepare();

    for (int i = 1; i <= n - m + 1; i++) printf("%d\n", query(i, i + m - 1));

    return 0;
}