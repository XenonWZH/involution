#include <cstdio>

const int MAXN = 1e8;

bool isNotPrime[MAXN + 1];
int primes[MAXN + 1], cnt;

inline void euler() {
    isNotPrime[0] = isNotPrime[1] = true;
    for (int i = 2; i <= MAXN; i++) {
        if (!isNotPrime[i]) {
            primes[++cnt] = i;
        }

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

    int n, q;
    scanf("%d %d", &n, &q);

    while (q--) {
        int k;
        scanf("%d", &k);
        printf("%d\n", primes[k]);
    }

    return 0;
}