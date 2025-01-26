#include <bits/stdc++.h>

typedef long long ll;

const int MAXN = 1e5;

bool isNotPrime[MAXN + 1];
int primes[MAXN + 1], cnt;

inline void euler() {
    isNotPrime[0] = isNotPrime[1] = true;
    for (int i = 2; i <= MAXN; i++) {
        if (!isNotPrime[i]) primes[++cnt] = i;
        for (int j = 1; j <= cnt; j++) {
            int t = i * primes[j];
            if (t > MAXN) break;
            isNotPrime[t] = true;
            if (i % primes[j] == 0) break;
        }
    }
}

void solve() {
    ll a;
    scanf("%lld", &a);

    std::vector<int> p;
    for (int i = 1; i <= cnt; i++) {
        if (primes[i] > a) break;
        if (a % primes[i] == 0) {
            int cnts = 0;
            while (a % primes[i] == 0) a /= primes[i], cnts++;
            if (cnts < 2) {
                puts("no");
                return;
            }
            p.push_back(cnts);
        }
    }

    ll t = round(pow(a, 0.5));
    if (t * t != a) {
        t = round(pow(a, 1.0 / 3));
        if (t * t * t != a) {
            puts("no");
            return;
        }
    }

    puts("yes");
}

int main() {
    euler();

    int n;
    scanf("%d", &n);

    while (n--) solve();

    return 0;
}