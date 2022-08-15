#include <cstdio>

long long gcd(long long a, long long b) {
    return b == 0 ? a : gcd(b, a % b);
}

long long phi(long long n) {
    long long ans = n;
    for (long long i = 2; i * i <= n; i++)
        if (n % i == 0) {
            ans = ans / i * (i - 1);
        while (n % i == 0) n /= i;
    }
    if (n > 1) ans = ans / n * (n - 1);
    return ans;
}

int main() {
#ifndef DBG
    freopen("gcd.in", "r", stdin);
    freopen("gcd.out", "w", stdout);
#endif

    int t;

    scanf("%d", &t);

    while (t--) {
        long long a, m;

        scanf("%lld %lld", &a, &m);

        printf("%lld\n", phi(m / gcd(a, m)));
    }

#ifndef DBG
    fclose(stdin);
    fclose(stdout);
#endif

    return 0;
}