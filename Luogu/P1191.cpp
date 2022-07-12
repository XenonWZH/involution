#include <cstring>
#include <iostream>

const int MAXN = 150;

int n;
int a[MAXN + 1][MAXN + 1];
int sum[MAXN + 1][MAXN + 1];

inline void calcSum() {
    memset(sum, 0, sizeof(sum));

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            sum[i][j] = sum[i][j - 1] + sum[i - 1][j] - sum[i - 1][j - 1] + a[i][j];
        }
    }
}

inline int getSq(int x1, int y1, int x2, int y2) {
    return sum[x2][y2] - sum[x2][y1 - 1] - sum[x1 - 1][y2] + sum[x1 - 1][y1 - 1];
}

int main() {
    std::cin >> n;

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            char ch;
            std::cin >> ch;
            a[i][j] = (ch == 'W' ? 0 : 1);
        }
    }

    calcSum();

    int ans = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (a[i][j]) continue;
            for (int k = i; k <= n; k++) {
                for (int l = j; l <= n; l++) {
                    if (a[k][l]) break;
                    if (getSq(i, j, k, l) == 0) {
                        ans++;
                    }
                }
            }
        }
    }

    std::cout << ans << std::endl;

    return 0;
}