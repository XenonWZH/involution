#include <cstdio>
#include <cstring>
#include <iostream>

const int MAXN = 500;

int main() {
    int t;

    scanf("%d", &t);

    while (t--) {
        int n, k, r, c;
        scanf("%d %d %d %d", &n, &k, &r, &c);

        static char ans[MAXN + 1][MAXN + 1];
        for (int i = 1; i <= k; i++) {
            for (int j = 1; j <= k; j++) {
                ans[i][j] = '.';
            }
        }

        r %= k, c %= k;
        if (r == 0) r = k;
        if (c == 0) c = k;

        int j = 1;
        ans[r][c] = 'X';
        for (int i = 1; i <= k; i++) {
            if (i == r) continue;
            if (j == c) j++;
            ans[i][j++] = 'X';
        }

        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                int x = i % k;
                int y = j % k;
                if (x == 0) x = k;
                if (y == 0) y = k;
                putchar(ans[x][y]);
            }
            putchar('\n');
        }
    }

    return 0;
}