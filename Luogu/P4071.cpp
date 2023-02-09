#include <cstdio>

const int MAXN = 1e6;
const int MOD = 1e9 + 7;

long long fac[MAXN + 1], inv[MAXN + 1], facInv[MAXN + 1];
long long d[MAXN + 1];

void prepare() {
    fac[0] = 1;
    for (int i = 1; i <= MAXN; i++) fac[i] = fac[i - 1] * i % MOD;

    inv[1] = 1;
    for (int i = 2; i <= MAXN; i++) inv[i] = (MOD - MOD / i) * inv[MOD % i] % MOD;

    facInv[0] = 1;
    for (int i = 1; i <= MAXN; i++) facInv[i] = facInv[i - 1] * inv[i] % MOD;

    d[0] = 1, d[1] = 0, d[2] = 1;
    for (int i = 3; i <= MAXN; i++) d[i] = (i - 1) * (d[i - 1] + d[i - 2]) % MOD;
}

long long C(int n, int m) {
    if (m < 0 || m > n) return 0;
    if (m == 0) return 1;
    return fac[n] * facInv[n - m] % MOD * facInv[m] % MOD;
}

int main() {
    int t;
    scanf("%d", &t);

    prepare();

    while (t--) {
        int n, m;
        scanf("%d %d", &n, &m);
        printf("%lld\n", C(n, m) * d[n - m] % MOD);
    }

    return 0;
}