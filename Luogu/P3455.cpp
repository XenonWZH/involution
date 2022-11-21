#include <cstdio>
#include <iostream>

const int MAXN = 5e4;

bool isNotPrime[MAXN + 1];
int mu[MAXN + 1], primes[MAXN + 1], cnt;
int sumMu[MAXN + 1];

inline void euler() {
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
}

int f(int n, int m, int k) {
    int ans = 0;

    n /= k, m /= k;
    for (int l = 1, r; l <= std::min(n, m); l = r + 1) {
        r = std::min(n / (n / l), m / (m / l));
        ans += (sumMu[r] - sumMu[l - 1]) * ((n / l) * (m / l));
    }

    return ans;
}

int main() {
    euler();

    int t;
    scanf("%d", &t);

    while (t--) {
        int a, b, d;
        scanf("%d %d %d", &a, &b, &d);

        printf("%d\n", f(a, b, d));
    }

    return 0;
}