#include <cstdio>

const int MAXN = 1000000;

int n;
long long a[MAXN], A, B, C;
long long s[MAXN + 1], f[MAXN + 1];

inline long long myPow(long long x) {
    return x * x;
}

inline long long y(const int a) {
    return f[a] + A * myPow(s[a]) - B * s[a];
}

inline long long x(const int a) {
    return s[a];
}

inline long long g(const int i) {
    return 2 * A * s[i];
}

inline double delta(const int a, const int b) {
    return (double)(y(a) - y(b)) / (x(a) - x(b));
}

int main() {
    int n;
    scanf("%d", &n);
    scanf("%lld %lld %lld", &A, &B, &C);
    for (int i = 0; i < n; i++) scanf("%lld", &a[i]);
    for (int i = 1; i <= n; i++) s[i] = s[i - 1] + a[i - 1];

    static long long q[MAXN + 1];

    long long *l = q, *r = q;
    *r = 0;

    for (int i = 1; i <= n; i++) {
        while (l < r && delta(*(l + 1), *l) > g(i)) l++;

        int j = *l;

        f[i] = f[j] + A * myPow(s[i] - s[j]) + B * (s[i] - s[j]) + C;

        while (l < r && delta(*r, *(r - 1)) < delta(i, *r)) r--;

        *++r = i;
    }

    printf("%lld\n", f[n]);

    return 0;
}