#include <cstdio>
#include <iostream>

const int MAXN = 1e7;

bool isNotPrime[MAXN + 1];
int mu[MAXN + 1], primes[MAXN + 1], cnt;
long long sumMu[MAXN + 1];

inline void getPrimes() {
    isNotPrime[0] = isNotPrime[1] = true;
    mu[1] = 1;
    for (int i = 2; i <= MAXN; i++) {
        if (!isNotPrime[i]) {
            primes[++cnt] = i;
            mu[i] = -1;
        }

        for (int j = 1; j <= cnt; j++) {
            int t = i * primes[j];
            if (t > MAXN) break;

            isNotPrime[t] = true;

            if (i % primes[j] == 0) {
                mu[t] = 0;
                break;
            } else mu[t] = -mu[i];
        }
    }

    for (int i = 1; i <= cnt; i++) {
        for (int j = 1; primes[i] * j <= MAXN; j++) {
            sumMu[primes[i] * j] += mu[j];
        }
    }
    for (int i = 2; i <= MAXN; i++) sumMu[i] += sumMu[i - 1];
}

inline long long f(int n) {
    long long ans = 0;
    for (int l = 1, r = 0; l <= n; l = r + 1) {
        r = n / (n / l);
        ans += (sumMu[r] - sumMu[l - 1]) * (n / l) * (n / l);
    }
    return ans;
}

int main() {
    getPrimes();

    int n;

    scanf("%d", &n);

    printf("%lld\n", f(n));

    return 0;
}