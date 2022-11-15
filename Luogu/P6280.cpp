#include <climits>
#include <cstdio>
#include <vector>

const int MAXN = 10000;

bool isNotPrime[MAXN + 1];
int primes[MAXN + 1], cnt;

inline void euler() {
    isNotPrime[0] = isNotPrime[1] = true;
    for (int i = 1; i <= MAXN; i++) {
        if (!isNotPrime[i]) primes[++cnt] = i;

        for (int j = 1; j <= cnt; j++) {
            int t = i * primes[j];
            if (t > MAXN) break;

            isNotPrime[t] = true;

            if (i % primes[j] == 0) break;
        }
    }
}


int main() {
    euler();

    int n, m;
    scanf("%d %d", &n, &m);

    while (cnt > 0 && primes[cnt] > n) cnt--;

    std::vector<std::vector<long long>> f(cnt + 1, std::vector<long long>(n + 1));
    f[0][0] = 1;

    for (int i = 1; i <= cnt; i++) {
        for (int j = 0; j <= n; j++) f[i][j] = f[i - 1][j];
        for (int j = primes[i]; j <= n; j++) {
            long long tmp = primes[i];
            while (tmp <= j) {
                f[i][j] = (f[i][j] + f[i - 1][j - tmp] * tmp % m) % m;
                tmp *= primes[i];
            }
        }
    }

    long long ans = 0;
    for (int i = 0; i <= n; i++) ans = (ans + f[cnt][i]) % m;

    printf("%lld\n", ans);

    return 0;
}