#include <bits/stdc++.h>

const int MAXN = 2e5;

bool isNotPrime[MAXN + 1];
int primes[MAXN + 1], cnt;

void euler() {
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

void solve() {
    int n;
    scanf("%d", &n);

    int p = 2;
    for (int i = 1; i <= cnt; i++) {
        if (primes[i] > n) break;
        if (std::min(p - 1, n - p) < std::min(primes[i] - 1, n - primes[i])) p = primes[i];
    }

    int delta = 1;
    printf("%d ", p);
    for (; p + delta <= n && p - delta > 0; delta++) {
        printf("%d %d ", p - delta, p + delta);
    }

    if (p - delta == 0) for (; p + delta <= n; delta++) printf("%d ", p + delta);
    else for (; p - delta > 0; delta++) printf("%d ", p - delta);

    puts("");
}

int main() {
    euler();

    int t;
    scanf("%d", &t);

    while (t--) solve();

    return 0;
}