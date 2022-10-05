#include <cstdio>
#include <cmath>
#include <algorithm>
 
const long long MOD = 998244353;
 
inline long long power(long long x, long long y) {
    long long p = MOD;
    long long re = 1 % p;
    while (y) {
        if (y & 1) re = (re * x) % p;
        x = (x * x) % p;
        y >>= 1;
    }
    return re;
}
 
inline long long inv(long long x) {
    long long p = MOD;
    return power(x, p - 2);
}
 
int main() {
    long long a, b, s, p0, p1;
 
    scanf("%lld %lld %lld %lld %lld", &a, &b, &s, &p0, &p1);

    long long pos = (inv(2) + inv(power(2, s + 1)) * (power(2, s) - 1) % MOD * (p1 - p0) % MOD * inv(100) % MOD) % MOD;
    long long ans = ((b - a) * pos % MOD + a) % MOD;

    printf("%lld\n", (ans + MOD) % MOD);
 
    return 0;
}