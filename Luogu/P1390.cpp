#include <cstdio>
#include <cstring>

const int MAXN = 2e6;

int v[MAXN + 1], prime[MAXN + 1], phi[MAXN + 1], m;

void euler(int n) {
    memset(v, 0, sizeof(v));
    phi[1] = 1, m = 0;
    for (int i = 2; i <= n; i++) {
        if (v[i] == 0) {
            v[i] = i;
            prime[++m] = i;
            phi[i] = i - 1;
        }
        for (int j = 1; j <= m; j++) {
            if (prime[j] > v[i] || prime[j] > n / i) break;
            v[i * prime[j]] = prime[j];
            phi[i * prime[j]] = phi[i] * (i % prime[j] ? prime[j] - 1 : prime[j]);
        }
    }
}

int main() {
    int n;
    scanf("%d", &n);

    euler(n);

    long long ans = 0;
    for (int i = 1; i <= n; i++) ans += 1ll * (n / i) * (n / i) * phi[i];
    ans = (ans - (1ll * n * n + n) / 2) / 2;

    printf("%lld\n", ans);

    return 0;
}