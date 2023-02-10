#include <cstdio>
#include <cstring>

typedef long long ll;
const int MAXN = 26;
const int MAXS = 100000;
const int MOD = 1e9 + 7;

struct Matrix {
    ll a[MAXN][MAXN];
    Matrix(bool unit) {
        memset(a, 0, sizeof(a));
        if (unit) for (int i = 0; i < MAXN; i++) a[i][i] = 1;
    }
};

Matrix operator*(Matrix a, Matrix b) {
    Matrix c(false);
    for (int i = 0; i < MAXN; i++) {
        for (int j = 0; j < MAXN; j++) {
            for (int k = 0; k < MAXN; k++) {
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
    ll n;
    scanf("%lld", &n);
    n--;

    static char s[MAXS + 1];
    scanf("%s", s);

    Matrix f(false);
    for (int i = 0; i < 26; i++) {
        for (int j = 0; j < 26; j++) {
            f.a[i][j] = 1;
        }
    }
    int len = strlen(s);
    for (int i = 1; i < len; i++) f.a[s[i - 1] - 'a'][s[i] - 'a'] = 0;

    Matrix a = power(f, n);

    ll ans = 0;
    for (int i = 0; i < 26; i++) {
        for (int j = 0; j < 26; j++) {
            ans = (ans + a.a[i][j]) % MOD;
        }
    }

    printf("%lld\n", ans);

    return 0;
}