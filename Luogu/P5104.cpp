#include <cstdio>

const int MOD = 1e9 + 7;

long long pow(long long a, long long b) {
    long long ans = 1;
    for (; b; b >>= 1, a = a * a % MOD) if (b & 1) ans = ans * a % MOD;
    return ans;
}

int main() {
    long long w, n, k;
    scanf("%lld %lld %lld", &w, &n, &k);

    printf("%lld\n", w * pow(pow(2, k), MOD - 2) % MOD);

    return 0;
}