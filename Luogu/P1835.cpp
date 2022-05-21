#include <cstdio>
#include <cstring>
#include <cmath>
#include <vector>
#include <algorithm>

const int MAXM = 1000000;

std::vector<int> primes;

inline void findPrime() {
    static bool isPrime[MAXM + 1];
    memset(isPrime, true, sizeof(isPrime));

    for (int i = 2; i <= MAXM; i++) {
        if (!isPrime[i]) continue;
        primes.push_back(i);

        for (int each : primes) {
            if (i * each > MAXM) break;
            isPrime[i * each] = false;
            if (i % each == 0) break;
        }
    }
}

int main() {
    findPrime();
    
    long long n, m;

    scanf("%lld %lld", &n, &m);

    static bool isPrime[MAXM + 1];
    memset(isPrime, true, sizeof(isPrime));

    for (int each : primes) {
        for (long long j = std::max(ceil(n * 1.0 / each), 2.0); j <= floor(m * 1.0 / each); j++) {
            isPrime[j * each - n] = false;
        }
    }

    long long ans = 0;
    for (int i = 0; i <= m - n; i++) {
        if (isPrime[i]) {
            ans++;
        }
    }

    printf("%lld\n", (n == 1 ? ans - 1 : ans));

    return 0;
}