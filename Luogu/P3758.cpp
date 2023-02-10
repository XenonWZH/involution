#include <cstdio>
#include <cstring>

typedef long long ll;
const int MAXN = 30;
const int MOD = 2017;

struct Matrix {
    ll a[MAXN + 1][MAXN + 1];
    Matrix(bool unit) {
        memset(a, 0, sizeof(a));
        if (unit) for (int i = 0; i <= MAXN; i++) a[i][i] = 1;
    }
};

Matrix operator*(Matrix a, Matrix b) {
    Matrix c(false);
    for (int i = 0; i <= MAXN; i++) {
        for (int j = 0; j <= MAXN; j++) {
            for (int k = 0; k <= MAXN; k++) {
                c.a[i][j] = (c.a[i][j] + a.a[i][k] * b.a[k][j] % MOD) % MOD;
            }
        }
    }
    return c;
}

Matrix power(Matrix a, ll b) {
    Matrix c(true);
    for (; b; b >>= 1, a = a * a) if (b & 1) c = c * a;
    return c;
}

int main() {
    int n, m;
    scanf("%d %d", &n, &m);

    Matrix f(true);
    for (int i = 1; i <= n; i++) f.a[i][0] = 1;
    for (int i = 1; i <= m; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        f.a[u][v] = f.a[v][u] = 1;
    }
    int t;
    scanf("%d", &t);

    Matrix a(false);
    a.a[0][1] = 1;
    a = a * power(f, t);

    ll ans = 0;
    for (int i = 0; i <= n; i++) ans = (ans + a.a[0][i]) % MOD;
    printf("%lld\n", ans);

    return 0;
}