#include <cstdio>

const int MAXN = (1 << 22);

int n;
unsigned int r1, r2, r3;
long long f[MAXN + 1], g[MAXN + 1];

inline unsigned int getf() {
    r1 ^= r1 << 16;
    r1 ^= r1 >> 5;
    r1 ^= r1 << 1;
    unsigned int t = r1;
    r1 = r2;
    r2 = r3;
    r3 ^= t ^ r1;
    return r3;
}

int main() {
    scanf("%d %u %u %u", &n, &r1, &r2, &r3);
    for (int i = 0; i < (1 << n); i++) g[i] = f[i] = getf();

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < (1 << n); j++) {
            if ((1 << i) & j) {
                g[j] += g[j ^ (1 << i)];
            }
        }
    }

    long long ans = 0;
    for (int i = 0; i < (1 << n); ++i) ans ^= g[i];

    printf("%lld\n", ans);

    return 0;
}
