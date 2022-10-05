#include <cstdio>
#include <iostream>

const int MAXN = 1e6;
const int MOD = 998244353;

long long fac[MAXN + 1];

inline int read() {
    int x = 0, w = 1;
    char ch = 0;
    while (ch < '0' || ch > '9') {
        if (ch == '-') w = -1;
        ch = getchar();
    }
    while (ch >= '0' && ch <= '9') {
        x = x * 10 + (ch - '0');
        ch = getchar();
    }
    return x * w;
}

inline void prepare() {
    fac[1] = 1;
    for (int i = 2; i <= MAXN; i++) fac[i] = fac[i - 1] * i % MOD;
}

int main() {
    prepare();

    int t;

    t = read();

    while (t--) {
        int n, k;
        n = read(); k = read();

        long long ans = 1;
        if (n == k) {
            ans = std::max(ans, fac[k - 1]);
        } else {
            ans = std::max(ans, fac[k]);
            int b = n - k - 1;
            for (; b; b >>= 1) {
                if (b & 1) ans = (long long)ans * n % MOD;
                n = (long long)n * n % MOD;
            }
        }

        printf("%lld\n", ans);
    }

    return 0;
}