#include <cstdio>
#include <iostream>
#include <vector>

const int MAXN = 5000;

int main() {
    long long x0, a, b, c, d;
    int n, m, q;

    scanf("%lld %lld %lld %lld %lld", &x0, &a, &b, &c, &d);
    scanf("%d %d %d", &n, &m, &q);

    std::vector<int> t(n * m + 1);
    long long x = x0;
    for (int i = 1; i <= n * m; i++) {
        t[i] = i;
        x = (a * x % d * x % d + b * x % d + c) % d;
        std::swap(t[i], t[x % i + 1]);
    }

    while (q--) {
        int u, v;
        scanf("%d %d", &u, &v);
        std::swap(t[u], t[v]);
    }

    std::vector<int> pos(n * m + 1);
    for (int i = 1; i <= n * m; i++) pos[t[i]] = i;

    auto getX = [m](int a) -> int { return (a - 1) / m + 1; };
    auto getY = [m](int a) -> int { return a % m ? a % m : m; };

    std::vector<int> l(n + 1, 1), r(n + 1, m);
    for (int i = 1; i <= n * m; i++) {
        if (getY(pos[i]) >= l[getX(pos[i])] && getY(pos[i]) <= r[getX(pos[i])]) {
            printf("%d ", i);
            for (int j = 1; j < getX(pos[i]); j++) r[j] = std::min(r[j], getY(pos[i]));
            for (int j = getX(pos[i]) + 1; j <= n; j++) l[j] = std::max(l[j], getY(pos[i]));
        }
    }
    putchar('\n');

    return 0;
}