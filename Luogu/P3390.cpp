#include <cstdio>
#include <cstring>
#include <iostream>

const int MAXN = 100;
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

Matrix pow(Matrix a, long long n) {
    Matrix res(true);
    for (; n; n >>= 1, a = a * a) if (n & 1) res = res * a;
    return res;
}

int main() {
    int n;
    long long k;
    Matrix a;

    scanf("%d %lld", &n, &k);
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            scanf("%lld", &a(i, j));
        }
    }

    a = pow(a, k);

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            printf("%lld ", (a(i, j) + MOD) % MOD);
        }
        putchar('\n');
    }

    return 0;
}