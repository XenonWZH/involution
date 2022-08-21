#include <cstdio>

int main() {
    int t;

    scanf("%d", &t);

    while (t--) {
        long long n, k, b, s;

        scanf("%lld %lld %lld %lld", &n, &k, &b, &s);

        if (k == 1) {
            if (b == s) {
                for (int i = 1; i <= n - 1; i++) printf("0 ");
                printf("%lld\n", b);
            } else puts("-1");
        } else if ((k - 1) * n + k * b >= s && k * b <= s) {
            s -= b * k;
            while (s > k - 1) {
                printf("%lld ", k - 1);
                s -= k - 1;
                n--;
            }
            printf("%lld ", s + b * k);
            n--;
            for (int i = 1; i <= n; i++) printf("0 ");
            putchar('\n');
        } else puts("-1");
    }

    return 0;
}