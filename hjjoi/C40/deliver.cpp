#include <algorithm>
#include <cstring>
#include <cstdio>

const int MAXN = 13;
const long long INF = 0x3f3f3f3f3f3f3f3f;

int n;
long long a[MAXN][MAXN];
int t[MAXN];
long long f1[1 << MAXN][MAXN], f2[1 << MAXN][MAXN];

inline void floyd() {
    for (int k = 0; k < n; k++) {
        for (int x = 0; x < n; x++) {
            for (int y = 0; y < n; y++) {
                a[x][y] = std::min(a[x][y], a[x][k] + a[k][y]);
            }
        }
    }
}

inline void dp() {
    memset(f1, 0x3f, sizeof(f1));
    memset(f2, 0x3f, sizeof(f2));
    f1[1][0] = f2[1][0] = 0;

    for (int i = 1; i < (1 << n); i++) {
        for (int j = 0; j < n; j++) {
            if (!((i >> j) & 1)) continue;

            for (int k = 0; k < n; k++) {
                // if ((i >> k) & 1) continue;
                if (f1[i][j] + a[j][k] <= t[k]) {
                    f2[i | (1 << k)][k] = std::min(f2[i | (1 << k)][k], f2[i][j] + f1[i][j] + a[j][k]);
                    f1[i | (1 << k)][k] = std::min(f1[i | (1 << k)][k], f1[i][j] + a[j][k]);
                }
            }
        }
    }
}

int main() {
#ifndef DBG
    freopen("deliver.in", "r", stdin);
    freopen("deliver.out", "w", stdout);
#endif

    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%lld", &a[i][j]);
        }
    }
    for (int i = 1; i < n; i++) scanf("%d", &t[i]);

    floyd();

    dp();

    long long ans = INF;
    for (int i = 0; i < n; i++) ans = std::min(ans, f2[(1 << n) - 1][i]);
    printf("%lld\n", ans == INF ? -1 : ans);

#ifndef DBG
    fclose(stdin);
    fclose(stdout);
#endif

    return 0;
}