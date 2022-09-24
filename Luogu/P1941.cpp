#include <cstdio>
#include <climits>
#include <iostream>
#include <algorithm>

const int MAXN = 10000;
const int MAXM = 1000;

struct Pip {
    int l, h;
    bool exist;
} pips[MAXN + 1];

int main() {
    int n, m, k;
    static int x[MAXN + 1], y[MAXN + 1];

    scanf("%d %d %d", &n, &m, &k);
    for (int i = 1; i <= n; i++) {
        scanf("%d %d", &x[i], &y[i]);
        pips[i].l = 0, pips[i].h = m + 1, pips[i].exist = false;
    }
    while (k--) {
        int p, l, h;
        scanf("%d %d %d", &p, &l, &h);
        pips[p].l = l, pips[p].h = h, pips[p].exist = true;
    }

    static int f[MAXN + 1][MAXM + 1];
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j <= m; j++) {
            f[i][j] = INT_MAX;
        }
    }
    for (int i = 1; i <= m; i++) f[0][i] = 0;

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j < m; j++) {
            if (j - x[i] > 0 && f[i - 1][j - x[i]] != INT_MAX) f[i][j] = std::min(f[i][j], f[i - 1][j - x[i]] + 1);
            if (j - x[i] > 0 && f[i][j - x[i]] != INT_MAX) f[i][j] = std::min(f[i][j], f[i][j - x[i]] + 1);
        }
        for (int j = 1; j <= m - y[i]; j++) {
            if (f[i - 1][j + y[i]] != INT_MAX) {
                f[i][j] = std::min(f[i][j], f[i - 1][j + y[i]]);
            }
        }
        for (int j = std::max(1, m - x[i]); j <= m; j++) {
            if (f[i - 1][j] != INT_MAX) f[i][m] = std::min(f[i][m], f[i - 1][j] + 1);
            if (f[i][j] != INT_MAX) f[i][m] = std::min(f[i][m], f[i][j] + 1);
        }
        for (int j = 0; j <= pips[i].l; j++) f[i][j] = INT_MAX;
        for (int j = pips[i].h; j <= m; j++) f[i][j] = INT_MAX;
    }

    int ans = INT_MAX;
    for (int i = 1; i <= m; i++) ans = std::min(ans, f[n][i]);

    if (ans == INT_MAX) {
        int cnt = 0;
        for (int i = 1; i <= n; i++) {
            if (!pips[i].exist) continue;
            for (int j = pips[i].l; j <= pips[i].h; j++) {
                if (f[i][j] != INT_MAX) {
                    cnt++;
                    break;
                }
            }
        }
        printf("0\n%d\n", cnt);
    } else printf("1\n%d\n", ans);

    return 0;
}