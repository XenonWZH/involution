#include <cstdio>

int main() {
    int t;

    scanf("%d", &t);

    while (t--) {
        long long n;

        scanf("%lld", &n);

        long long a[7] = { 0, 1, 4, 7, 10, 11, 16 };

        printf("%lld\n", n / 6 * a[6] + a[n % 6]);
    }

    return 0;
}