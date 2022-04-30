#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>

const int MAXN = 300;

int n, m, score[MAXN + 1];
std::vector<int> e[MAXN + 1];
int f[MAXN + 1][MAXN + 1];

void dp(int x) {
    f[x][0] = 0;
    for (int y : e[x]) {
        dp(y);
        for (int t = n; t >= 0; t--) {
            for (int j = 0; j <= t; j++) {
                f[x][t] = std::max(f[x][t], f[x][t - j] + f[y][j]);
            }
        }
    }

    if (x != 0) {
        for (int t = n; t > 0; t--) {
            f[x][t] = f[x][t - 1] + score[x];
        }
    }
}

int main() {
    scanf("%d%d", &n, &m);

    score[0] = 0;
    for (int i = 1, k, s; i <= n; i++) {
        scanf("%d%d", &k, &s);
        e[k].push_back(i);
        score[i] = s;
    }

    memset(f, 0xcf, sizeof(f));

    dp(0);

    printf("%d\n", f[0][m]);

    return 0;
}