#include <cstdio>

const int MAXN = 50, MOD = 10000007;

inline long long power(long long a, long long b) {
    long long ans = 1;
    while (b > 0) {
        if (b & 1 == 1) {
            ans = ans * a % MOD;
        }
        a = a * a % MOD;
        b >>= 1;
    }
    return ans;
}

int main() {
    long long n;

    scanf("%lld", &n);

    static long long f[MAXN];
    long long counts = 0;

    for (int i = MAXN - 1; i >= 0; i--) {
        for (int j = MAXN - 1; j > 0; j--) f[j] += f[j - 1];
        if (n >> i & 1) f[counts++]++;
    }
    f[counts]++;

    long long ans = 1;
    for (int i = 1; i < MAXN; i++) {
        ans = ans * power(i, f[i]) % MOD;
    }

    printf("%lld\n", ans);

    return 0;
}