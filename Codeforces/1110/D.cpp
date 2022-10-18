#include <cstdio>
#include <cstring>
#include <iostream>

const int MAXN = 1e6;

int main() {
    int n, m;
    static int a[MAXN + 1];

    scanf("%d %d", &n, &m);
    for (int i = 0; i < n; i++) {
        int x;
        scanf("%d", &x);
        a[x]++;
    }

    static int f[MAXN + 1][3][3];
    memset(f, -1, sizeof(f));
    f[0][0][0] = 0;

    for (int i = 1; i <= m; i++) {
        for (int j = 0; j < 3; j++) {
            for (int k = 0; k < 3; k++) {
                for (int l = 0; l < 3; l++) {
                    if (a[i] < j + k + l) continue;
                    f[i][k][l] = std::max(f[i][k][l], f[i - 1][j][k] + (a[i] - j - k - l) / 3 + l);
                }
            }
        }
    }

    printf("%d\n", f[m][0][0]);

    return 0;
}