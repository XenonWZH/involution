#include <cstdio>
#include <iostream>

const int MAXN = 1e5;

bool isNotPrime[MAXN + 1];
int mu[MAXN + 1], primes[MAXN + 1], cnt;
long long sumMu[MAXN + 1];

inline void getPrimes(int n) {
    isNotPrime[0] = isNotPrime[1] = true;
    mu[1] = 1;
    for (int i = 2; i <= n; i++) {
        if (!isNotPrime[i]) {
            primes[++cnt] = i;
            mu[i] = -1;
        }

        for (int j = 1; j <= cnt; j++) {
            int t = i * primes[j];
            if (t > n) break;

            isNotPrime[t] = true;

            if (i % primes[j] == 0) {
                mu[t] = 0;
                break;
            } else mu[t] = -mu[i];
        }
    }

    sumMu[0] = 0;
    for (int i = 1; i <= n; i++) sumMu[i] = sumMu[i - 1] + mu[i];
}

long long f(int n, int k) {
    long long ans = 0;

    n /= k;
    for (int l = 1, r; l <= n; l = r + 1) {
        r = n / (n / l);
        ans += (sumMu[r] - sumMu[l - 1]) * (1ll * (n / l) * (n / l));
    }

    return ans;
}

int main() {
    int n;

    scanf("%d", &n);

    getPrimes(n);

    long long ans = 0;
    for (int i = 1; i <= n; i++) ans += f(n, i) * i;

    printf("%lld\n", ans);

    return 0;
}
