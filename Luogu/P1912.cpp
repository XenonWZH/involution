#include <bits/stdc++.h>

namespace XenonWZH {
const int MAXN = 1e5;

inline long double pow(long double b, int n) {
    long double a = 1;
    for (; n; n >>= 1, b *= b) if (n & 1) a *= b;
    return a;
}

void solve() {
    int n, l, p;
    scanf("%d %d %d", &n, &l, &p);
    l++;

    static char str[MAXN + 1][33];
    std::vector<int> s(n + 1);
    for (int i = 1; i <= n; ++i) {
        scanf("%s", str[i]);
        s[i] = s[i - 1] + strlen(str[i]) + 1;
    }

    std::vector<long double> f(n + 1);
    std::vector<int> q(n + 1);
    int h = 1, t = 1;
    q[1] = 0;

    auto calc = [&](int i, int j) {
        return f[j] + pow(std::abs(s[i] - s[j] - l), p);
    };

    auto binarySearch = [&](int x, int y) {
        int l = x, r = n + 1, m;
        while (l < r) {
            m = l + (r - l) / 2;
            calc(m, x) >= calc(m, y) ? r = m : l = m + 1;
        }
        return l;
    };

    std::vector<int> k(n + 1), pr(n + 1);
    for (int i = 1; i <= n; ++i) {
        while (h < t && k[h] <= i) ++h;
        f[i] = calc(i, q[h]);
        pr[i] = q[h];
        while (h < t && k[t - 1] >= binarySearch(q[t], i)) --t;
        k[t] = binarySearch(q[t], i);
        q[++t] = i;
    }

    if (f[n] > 1e18) {
        puts("Too hard to arrange");
        puts("--------------------");
        return;
    }

    printf("%.0Lf\n", f[n]);
    t = 0, q[0] = n;
    for (int i = n; i; q[++t] = i = pr[i]) continue;
    for (; t; t--) {
        for (int i = q[t] + 1; i < q[t - 1]; i++) printf("%s ", str[i]);
        puts(str[q[t - 1]]);
    }
    puts("--------------------");
}

int main() {
    int t;
    scanf("%d", &t);

    while (t--) solve();

    return 0;
}
};

int main() {
    return XenonWZH::main();
}