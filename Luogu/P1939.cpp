#include <cstdio>
#include <cstring>
#include <iostream>

const int MAXN = 3;
const int MOD = 1e9 + 7;

struct Matrix {
    long long a[MAXN + 1][MAXN + 1];

    Matrix(const bool unit = false) {
        memset(a, 0, sizeof(a));
        if (unit) for (int i = 1; i <= MAXN; i++) a[i][i] = true;
    }

    long long &operator()(const int i, const int j) { return a[i][j]; }
    const long long &operator()(const int i, const int j) const { return a[i][j]; }
};

Matrix operator*(const Matrix &a, const Matrix &b) {
    Matrix res(false);
    for (int i = 1; i <= MAXN; i++) {
        for (int j = 1; j <= MAXN; j++) {
            for (int k = 1; k <= MAXN; k++) {
                res(i, j) = (res(i, j) + (a(i, k) * b(k, j) % MOD)) % MOD;
            }
        }
    }
    return res;
}

Matrix pow(Matrix a, int n) {
    Matrix res(true);
    for (; n; n >>= 1, a = a * a) if (n & 1) res = res * a;
    return res;
}

void solve() {
    int n;
    scanf("%d", &n);

    if (n >= 1 && n <= 3) {
        puts("1");
        return;
    }

    Matrix a, b;
    a(1, 1) = a(1, 2) = a(1, 3) = 1;
    b(1, 1) = b(1, 2) = b(2, 3) = b(3, 1) = 1;

    printf("%lld\n", (a * pow(b, n - 3))(1, 1));
}

int main() {
    int t;

    scanf("%d", &t);

    while (t--) solve();

    return 0;
}