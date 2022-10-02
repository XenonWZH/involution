#include <cstdio>
#include <iostream>

const int MOD = 998244353;

inline long long pow(const long long n, const long long k) {
    long long ans = 1;
    for (long long num = n, t = k; t; num = num * num % MOD, t >>= 1) {
        if (t & 1) {
            ans = ans * num % MOD;
        }
    }
    return ans;
}

int main() {
    long long n, k;

    scanf("%lld %lld", &n, &k);

    printf("%lld\n", pow((pow(2, k) - 1 + MOD) % MOD, n));

    return 0;
}