#include <cstdio>
#include <cstring>
#include <iostream>

const int MAXN = 1000;
const int MAXM = 200;
const int MOD = 1e9 + 7;

int main() {
    long long n, m, k;
    static char a[MAXN + 1], b[MAXM + 1];

    scanf("%lld %lld %lld", &n, &m, &k);
    scanf("%s", a);
    scanf("%s", b);

    static long long f[MAXM + 1][MAXM + 1], s[MAXM + 1][MAXM + 1];
    memset(f, 0, sizeof(0));
    f[0][0] = 1;

    for (int i = 1; i <= n; i++) {
        for (int j = m; j >= 1; j--) {
            for (int l = k; l >= 1; l--) {
                s[j][l] = a[i - 1] == b[j - 1] ? s[j - 1][l] + f[j - 1][l - 1] : 0;
                f[j][l] = (f[j][l] + s[j][l]) % MOD;
            }
        }
    }

    printf("%lld\n", f[m][k]);

    return 0;
}