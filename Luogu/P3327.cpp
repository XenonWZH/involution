#include <cstdio>
#include <iostream>

const int MAXN = 5e4;

bool isNotPrime[MAXN + 1];
int mu[MAXN + 1], primes[MAXN + 1], cnt;
long long sumMu[MAXN + 1], sum[MAXN + 1];

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

    sumMu[0] = 0;
    for (int i = 1; i <= MAXN; i++) sumMu[i] = sumMu[i - 1] + mu[i];
    for (int i = 1; i <= MAXN; i++) {
        for (int l = 1, r = 0; l <= i; l = r + 1) {
            r = i / (i / l);
            sum[i] += (long long)(r - l + 1) * (i / l);
        }
    }
}

inline long long f(int n, int m) {
    long long ans = 0;
    for (int l = 1, r = 0; l <= std::min(n, m); l = r + 1) {
        r = std::min(n / (n / l), m / (m / l));
        ans += (sumMu[r] - sumMu[l - 1]) * sum[n / l] * sum[m / l];
    }
    return ans;
}

int main() {
    getPrimes();

    int t;

    scanf("%d", &t);

    while (t--) {
        int n, m;

        scanf("%d %d", &n, &m);

        printf("%lld\n", f(n, m));
    }

    return 0;
}