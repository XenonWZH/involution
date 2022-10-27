#include <cstdio>
#include <cstring>

const int MAXSTATUS = 2;

struct Matrix {
    long long a[MAXSTATUS][MAXSTATUS];

    Matrix(bool unit = false) {
        memset(a, 0, sizeof(a));
        if (unit) for (int i = 0; i < MAXSTATUS; i++) a[i][i] = 1;
    }

    long long &operator()(int i, int j) { return a[i][j]; }
    const long long &operator()(int i, int j) const { return a[i][j]; }
};

int p, q, a1, a2, n, m;

Matrix operator*(Matrix a, Matrix b) {
    Matrix res(false);
    for (int i = 0; i < MAXSTATUS; i++) for (int j = 0; j < MAXSTATUS; j++) for (int k = 0; k < MAXSTATUS; k++) res(i, j) = (res(i, j) + a(i, k) * b(k, j) % m) % m;
    return res;
}

Matrix pow(Matrix a, int n) {
    Matrix res(true);
    for (; n; n >>= 1, a = a * a) if (n & 1) res = res * a;
    return res;
}

int main() {
    scanf("%d %d %d %d %d %d", &p, &q, &a1, &a2, &n, &m);

    if (n == 1) {
        printf("%d\n", a1 % p);
        return 0;
    }

    Matrix a, b;
    a(0, 0) = a2, a(0, 1) = a1;
    b(0, 0) = p, b(0, 1) = 1, b(1, 0) = q, b(1, 1) = 0;

    printf("%lld\n", (a * pow(b, n - 2))(0, 0));

    return 0;
}