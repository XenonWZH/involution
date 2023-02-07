#include <cstdio>
#include <cstring>

const int MAXN = 1000;
const int MOD = 1e9 + 7;

int n, m;
long long a[MAXN + 1][MAXN + 1], b[MAXN + 1][MAXN + 1];
long long aRow[MAXN + 1], aCol[MAXN + 1], aSum;
long long bRow[MAXN + 1], bCol[MAXN + 1], bSum;
long long row[MAXN + 1], col[MAXN + 1];

void prepare() {
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            aRow[i] = (aRow[i] + a[i][j]) % MOD;
            aCol[j] = (aCol[j] + a[i][j]) % MOD;
            aSum = (aSum + a[i][j]) % MOD;
        }
    }
}

long long pow(long long a, long long k) {
    long long res = 1;
    for (; k; k >>= 1, a = a * a % MOD)
        if (k & 1) res = res * a % MOD;
    return res;
}

long long inv(long long a) {
    return pow(a, MOD - 2);
}

void calc() {
    bSum = (aSum * inv(n + m - 1)) % MOD;
    for (int i = 1; i <= n; i++) bRow[i] = (aRow[i] - bSum + MOD) % MOD * inv(m - 1);
    for (int i = 1; i <= m; i++) bCol[i] = (aCol[i] - bSum + MOD) % MOD * inv(n - 1);
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            b[i][j] = (bRow[i] + bCol[j] - a[i][j] + MOD) % MOD;
        }
    }
}

int main() {
    scanf("%d %d", &n, &m);
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            scanf("%lld", &a[i][j]);
        }
    }

    if (n == 1 || m == 1) {
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                if (a[i][j] != a[1][1]) {
                    puts("-1");
                    return 0;
                }
            }
        }
        puts("1");
        if (n == 1) {
            for (int i = 1; i <= m - 1; i++) printf("0 ");
            printf("%lld\n", a[1][1]);
        } else {
            for (int i = 1; i <= n - 1; i++) printf("0 ");
            printf("%lld\n", a[1][1]);
        }
        return 0;
    }

    prepare();
    calc();

    puts("1");
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            printf("%lld ", b[i][j]);
        }
        puts("");
    }

    return 0;
}