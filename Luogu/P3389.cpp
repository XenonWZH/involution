#include <cstdio>
#include <iostream>

const int MAXN = 100;

int n;
double a[MAXN + 1][MAXN + 2];

bool gauss() {
    for (int i = 1; i <= n; i++) {
        if (a[i][i] == 0) return false;

        for (int j = i + 1; j <= n + 1; j++) a[i][j] /= a[i][i];
        a[i][i] = 1;

        for (int j = i + 1; j <= n; j++) {
            for (int k = i + 1; k <= n + 1; k++) {
                a[j][k] -= a[i][k] * a[j][i] / a[i][i];
            }
            a[j][i] = 1;
        }
    }

    return true;
}

void solve() {
    for (int i = n; i > 1; i--) {
        for (int j = 1; j < i; j++) {
            a[j][n + 1] -= a[i][n + 1] * a[j][i] / a[i][i];
            a[j][i] = 0;
        }
    }
}

int main() {
    std::cin >> n;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n + 1; j++) {
            scanf("%lf", &a[i][j]);
        }
    }

    if (!gauss()) {
        std::cout << "No Solution" << std::endl;
        return 0;
    }

    solve();

    for (int i = 1; i <= n; i++) {
        printf("%.2f\n", a[i][n + 1]);
    }

    return 0;
}