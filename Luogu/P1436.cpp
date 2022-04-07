#include <cstdio>
#include <cstring>
#include <iostream>

const int MAXB = 8, MAXN = 15;

int n;
int board[MAXB + 1][MAXB + 1], s[MAXB + 1][MAXB + 1];
int f[MAXN + 1][MAXB + 1][MAXB + 1][MAXB + 1][MAXB + 1];

inline int getTri(int l, int d, int r, int u) {
    return s[r][u] - s[r][d - 1] - s[l - 1][u] + s[l - 1][d - 1];
}

inline int pow(int x) {
    return x * x;
}

inline void init() {
    memset(s, 0, sizeof(s));
    memset(f, 0x3f, sizeof(f));

    for (int i = 1; i <= MAXB; i++) {
        for (int j = 1; j <= MAXB; j++) {
            s[i][j] = s[i - 1][j] + s[i][j - 1] - s[i - 1][j - 1] + board[i][j];
        }
    }

    for (int l = 1; l <= MAXB; l++) {
        for (int d = 1; d <= MAXB; d++) {
            for (int r = l; r <= MAXB; r++) {
                for (int u = d; u <= MAXB; u++) {
                    f[1][l][d][r][u] = pow(getTri(l, d, r, u));
                }
            }
        }
    }
}

inline void dp() {
    for (int i = 2; i <= n; i++) {
        for (int l = 1; l <= MAXB; l++) {
            for (int d = 1; d <= MAXB; d++) {
                for (int r = l; r <= MAXB; r++) {
                    for (int u = d; u <= MAXB; u++) {
                        for (int j = l; j < r; j++) f[i][l][d][r][u] = std::min(f[i][l][d][r][u], std::min(f[i - 1][l][d][j][u] + f[1][j + 1][d][r][u], f[1][l][d][j][u] + f[i - 1][j + 1][d][r][u]));
                        for (int j = d; j < u; j++) f[i][l][d][r][u] = std::min(f[i][l][d][r][u], std::min(f[i - 1][l][d][r][j] + f[1][l][j + 1][r][u], f[1][l][d][r][j] + f[i - 1][l][j + 1][r][u]));
                    }
                }
            }
        }
    }
}

int main() {
    std::cin >> n;
    for (int i = 1; i <= MAXB; i++) {
        for (int j = 1; j <= MAXB; j++) {
            scanf("%d", &board[i][j]);
        }
    }

    init();

    dp();

    std::cout << f[n][1][1][MAXB][MAXB] << std::endl;

    return 0;
}