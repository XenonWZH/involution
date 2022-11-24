#include <cstdio>
#include <cstring>

const int MOD = 1e9 + 7;
const int MAXSTATUS = 5;

struct Matrix {
    long long a[MAXSTATUS][MAXSTATUS];

    Matrix(bool unit = false) {
        memset(a, 0, sizeof(a));
        if (unit) for (int i = 0; i < MAXSTATUS; i++) a[i][i] = 1;
    }

    long long &operator()(int i, int j) { return a[i][j]; }
    const long long &operator()(int i, int j) const { return a[i][j]; }
};

Matrix operator*(Matrix a, Matrix b) {
    Matrix res(false);
    for (int i = 0; i < MAXSTATUS; i++) for (int j = 0; j < MAXSTATUS; j++) for (int k = 0; k < MAXSTATUS; k++) res(i, j) = (res(i, j) + a(i, k) * b(k, j) % MOD) % MOD;
    return res;
}

Matrix pow(Matrix a, long long n) {
    Matrix res(true);
    for (; n; n >>= 1, a = a * a) if (n & 1) res = res * a;
    return res;
}

int main() {
    int t;
    scanf("%d", &t);

    Matrix s;
    s(0, 1) = s(1, 0) = s(1, 1) = s(2, 3) = s(3, 2) = s(3, 3) = s(4, 4) = 1;
    s(3, 1) = 2;
    s(4, 1) = MOD - 1;

    while (t--) {
        long long n;
        scanf("%lld", &n);

        if (n < 3) {
            puts("0");
            continue;
        }

        Matrix a;
        a(0, 2) = 1;
        a(0, 3) = a(0, 4) = 2;

        printf("%lld\n", (a * pow(s, n - 2))(0, 1));
    }

    return 0;
}