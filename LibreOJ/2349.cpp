#include <cstdio>
#include <cstring>
#include <algorithm>

const int MAXN = 3000;

int n, m;
int f[MAXN + 1][3], ans;
char gird[MAXN + 1][MAXN + 1];

inline void dp() {
    for (int i = 2; i <= m; i++) {
        int counts = 0;
        memset(f, 0, sizeof(f));
        int x = 1, y = i;

        while (x <= n && y > 0) {
            f[x][0] = std::max(f[x - 1][1], std::max(f[x - 1][2], f[x - 1][0]));

            if (gird[x][y] == 'G') {
                if (gird[x][y - 1] == 'R' && gird[x][y + 1] == 'W') {
                    f[x][1] = std::max(f[x - 1][1], f[x - 1][0]) + 1;
                }

                if (gird[x + 1][y] == 'W' && gird[x - 1][y] == 'R') {
                    f[x][2] = std::max(f[x - 1][2], f[x - 1][0]) + 1;
                }
            }

            counts = std::max(f[x][0], std::max(f[x][1], f[x][2]));
            x++, y--;
        }

        ans += counts;
    }

    for (int i = 2; i <= n; i++) {
        int counts = 0;
        memset(f, 0, sizeof(f));
        int x = i, y = m;

        while (x <= n && y > 0) {
            f[x][0] = std::max(f[x - 1][1], std::max(f[x - 1][2], f[x - 1][0]));

            if (gird[x][y] == 'G') {
                if (gird[x + 1][y] == 'W' && gird[x - 1][y] == 'R') {
                    f[x][2] = std::max(f[x - 1][2], f[x - 1][0]) + 1;
                }

                if (gird[x][y - 1] == 'R' && gird[x][y + 1] == 'W') {
                    f[x][1] = std::max(f[x - 1][1], f[x - 1][0]) + 1;
                }
            }

            counts = std::max(f[x][0], std::max(f[x][1], f[x][2]));
            x++, y--;
        }

        ans += counts;
    }
}

int main() {
    scanf("%d %d", &n, &m);

    for (int i = 1; i <= n; i++) {
        scanf("%s", gird[i] + 1);
    }

    dp();

    printf("%d\n", ans);

    return 0;
}