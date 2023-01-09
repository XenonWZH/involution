#include <cstdio>
#include <cmath>
#include <map>

long long pow(long long a, long long b, long long p) {
    long long ans = 1;
    for (; b; a = a * a % p, b >>= 1) if (b & 1) ans = ans * a % p;
    return ans;
}

long long inv(long long a, long long p) {
    return pow(a, p - 2, p);
}

long long bsgs(long long a, long long b, long long n) {
    long long m = sqrt(n + 0.5);
    long long v = inv(pow(a, m, n), n);
    std::map<long long, long long> x;
    x[1] = 0;

    long long e = 1;
    for (int i = 1; i < m; i++) {
        e = e * a % n;
        if (!x.count(e)) x[e] = i;
    }

    for (int i = 0; i < m; i++) {
        if (x.count(b)) return i * m + x[b];
        b = b * v % n;
    }

    return -1;
}

int main() {
    long long a, b, n;
    scanf("%lld %lld %lld", &n, &a, &b);

    long long ans = bsgs(a, b, n);
    if (ans == -1) puts("no solution");
    else printf("%lld\n", bsgs(a, b, n));

    return 0;
}