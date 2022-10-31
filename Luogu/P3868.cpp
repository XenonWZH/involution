#include <cstdio>
#include <vector>

int exgcd(long long a, long long b, long long &x, long long &y) {
    if (b == 0) {
        x = 1;
        y = 0;
        return a;
    }
    long long d = exgcd(b, a % b, x, y);
    long long t = x;
    x = y;
    y = t - (a / b) * y;
    return d;
}

long long qmul(long long a, long long b, long long p) {
    long long ans = 0;
    for (; b; b >>= 1, a = 2 * a % p) if (b & 1) ans = (ans + a) % p;
    return ans;
}

long long crt(int k, std::vector<long long> &a, std::vector<long long> &r) {
    long long n = 1, ans = 0;
    for (int i = 1; i <= k; i++) n *= r[i];
    for (int i = 1; i <= k; i++) {
        long long m = n / r[i], b, y;
        exgcd(m, r[i], b, y);
        b = (b % n + n) % n;
        ans = (ans + qmul(qmul(a[i], m, n), b, n) % n) % n;
    }
    return (ans % n + n) % n;
}

int main() {
    int k;
    scanf("%d", &k);
    
    std::vector<long long> a(k + 1), b(k + 1);
    for (int i = 1; i <= k; i++) scanf("%lld", &a[i]);
    for (int i = 1; i <= k; i++) scanf("%lld", &b[i]);
    for (int i = 1; i <= k; i++) a[i] %= b[i];
    
    printf("%lld\n", crt(k, a, b));
    
    return 0;
}
