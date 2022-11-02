#include <cstdio>
#include <vector>
#include <algorithm>

int main() {
    int n, m, t;
    scanf("%d %d %d", &n, &m, &t);

    std::vector<int> x(t + 1), y(t + 1);
    for (int i = 1; i <= t; i++) scanf("%d %d", &x[i], &y[i]);

    if (t % n == 0 && t % m == 0) printf("both ");
    else if (t % n == 0) printf("row ");
    else if (t % m == 0) printf("column ");
    else {
        puts("impossible");
        return 0;
    }

    long long ans = 0;

    if (t % n == 0) {
        std::vector<int> a(n + 1, 0), s(n + 1);
        int each = t / n;

        for (int i = 1; i <= t; i++) a[x[i]]++;
        for (int i = 1; i <= n; i++) a[i] -= each;

        s[0] = 0;
        for (int i = 1; i <= n; i++) s[i] = s[i - 1] + a[i];
        std::sort(s.begin() + 1, s.end());
        for (int i = 1; i <= n / 2; i++) ans += s[n - i + 1] - s[i];
    }

    if (t % m == 0) {
        std::vector<int> a(m + 1, 0), s(m + 1);
        int each = t / m;

        for (int i = 1; i <= t; i++) a[y[i]]++;
        for (int i = 1; i <= m; i++) a[i] -= each;

        s[0] = 0;
        for (int i = 1; i <= m; i++) s[i] = s[i - 1] + a[i];
        std::sort(s.begin() + 1, s.end());
        for (int i = 1; i <= m / 2; i++) ans += s[m - i + 1] - s[i];
    }

    printf("%lld\n", ans);

    return 0;
}