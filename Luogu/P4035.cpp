#include <cstdio>
#include <iostream>

const int MAXN = 10;

int n;
double pos[MAXN + 2][MAXN + 1], a[MAXN + 1][MAXN + 2];

void gauss() {
    for (int i = 1; i <= n; i++) {

        for (int j = i + 1; j <= n + 1; j++) a[i][j] /= a[i][i];
        a[i][i] = 1;

        for (int j = i + 1; j <= n; j++) {
            for (int k = i + 1; k <= n + 1; k++) {
                a[j][k] -= a[i][k] * a[j][i] / a[i][i];
            }
            a[j][i] = 1;
        }
    }
}

void solve() {
    for (int i = n; i > 1; i--) {
        for (int j = 1; j < i; j++) {
            a[j][n + 1] -= a[i][n + 1] * a[j][i] / a[i][i];
            a[j][i] = 0;
        }
    }
}

void init() {
    for (int i = 1; i <= n; i++) {
        a[i][n + 1] = 0;
        for (int j = 1; j <= n; j++) {
            a[i][j] = 2 * (pos[i][j] - pos[i + 1][j]);
            a[i][n + 1] += pos[i][j] * pos[i][j] - pos[i + 1][j] * pos[i + 1][j];
        }
    }
}

int main() {

    std::cin >> n;

    for (int i = 1; i <= n + 1; i++) {
        for (int j = 1; j <= n; j++) {
            std::cin >> pos[i][j];
        }
    }

    init();

    gauss();

    solve();

    for (int i = 1; i <= n; i++) {
        printf("%.3f ", a[i][n + 1]);
    }
    std::cout << std::endl;

    return 0;
}