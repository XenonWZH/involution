#include <cstdio>
#include <cstring>
#include <algorithm>

const int MAXN = 100;

int main() {
    int n;
    static int a[2 * MAXN];

    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
        a[i + n] = a[i];
    }

    static int f[2 * MAXN][2 * MAXN];
    int mx = 0;
    memset(f, 0, sizeof(f));

    for (int i = 1; i < 2 * n; i++) {
        for (int j = i - 1; j >= 0 && i - j < n; j--) {
            for (int k = j; k < i; k++) {
                f[j][i] = std::max(f[j][i], f[j][k] + f[k + 1][i] + a[j] * a[k + 1] * a[i + 1]);
                mx = std::max(mx, f[j][i]);
            }
        }
    }

    printf("%d\n", mx);

    return 0;
}