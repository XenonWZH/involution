#include <cstdio>
#include <cstring>
#include <iostream>

const int MAXN = 1000000;

int main() {
    int n, m;
    static long long a[MAXN + 10];
    memset(a, 0, sizeof(a));

    std::cin >> n >> m;

    for (int i = 0; i < m; i++) {
        long long l, r, b, d;
        scanf("%lld%lld%lld%lld", &l, &r, &b, &d);

        a[l] += b;
        a[l + 1] += d - b;
        a[r + 1] -= b + (r - l) * d + d;
        a[r + 2] += b + (r - l) * d;
    }

    long long plus = 0, sum = 0;
    for (int i = 1; i <= n; i++) {
        plus += a[i];
        sum += plus;
        printf("%lld ", sum);
    }
    std::cout << std::endl;

    return 0;
}