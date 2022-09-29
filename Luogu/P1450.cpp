#include <cstdio>

const int MAXN = 1e5;

int main() {
    int c[5], n;

    scanf("%d %d %d %d %d", &c[1], &c[2], &c[3], &c[4], &n);

    static long long f[MAXN + 1];
    f[0] = 1;
    for (int i = 1; i <= 4; i++) {
        for (int j = c[i]; j <= MAXN; j++) {
            f[j] += f[j - c[i]];
        }
    }

    while (n--) {
        int d[5], s;
        scanf("%d %d %d %d %d", &d[1], &d[2], &d[3], &d[4], &s);

        long long ans = 0;
        for (int i = 0; i < (1 << 4); i++) {
            long long res = s;
            int flag = 0;
            for (int j = 1; j <= 4; j++) {
                if ((i >> (j - 1)) & 1) {
                    res -= c[j] * (d[j] + 1);
                    flag ^= 1;
                }
            }
            if (res < 0) continue;
            if (!flag) ans += f[res];
            else ans -= f[res];
        }

        printf("%lld\n", ans);
    }

    return 0;
}