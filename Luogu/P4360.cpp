#include <cstdio>
#include <climits>
#include <vector>
#include <algorithm>

int main() {
    int n;
    scanf("%d", &n);

    std::vector<long long> w(n + 1), d(n + 1);
    for (int i = 1; i <= n; i++) scanf("%lld %lld", &w[i], &d[i]);

    std::vector<long long> sw(n + 1), sd(n + 1), md(n + 1);
    for (int i = 1; i <= n; i++) {
        sw[i] = sw[i - 1] + w[i];
        sd[i] = sd[i - 1] + d[i];
        md[i] = md[i - 1] + sw[i] * d[i];
    }

    std::vector<long long> f(n + 2, LLONG_MAX), g(n + 2, LLONG_MAX);
    f[0] = 0;

    auto slope = [&](int x, int y) {
        return 1.0 * ((g[x] - md[std::max(0, x - 1)] + sw[x] * sd[std::max(0, x - 1)]) -
                      (g[y] - md[std::max(0, y - 1)] + sw[y] * sd[std::max(0, y - 1)])) / 
                     (sw[x] - sw[y]);
    };

    for (int _ = 1; _ <= 3; _++) {
        g = f;
        std::fill(f.begin(), f.end(), LLONG_MAX);
        f[0] = 0;

        std::vector<int> q(n + 2);
        auto l = q.begin(), r = q.begin();
        q[0] = 0;

        for (int i = 1; i <= n + 1; i++) {
            while (l < r && slope(*(l), *(l + 1)) < sd[i - 1]) l++;

            int &j = *l;
            f[i] = g[j] + (md[std::max(0, i - 1)] - md[std::max(0, j - 1)]) - sw[j] * (sd[std::max(0, i - 1)] - sd[std::max(0, j - 1)]);

            if (g[i] != LLONG_MAX) {
                while (l < r && slope(*(r - 1), *r) > slope(*r, i)) r--;
                *(++r) = i;
            }
        }
    }

    printf("%lld\n", f[n + 1]);

    return 0;
}