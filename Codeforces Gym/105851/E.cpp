#include <bits/stdc++.h>

namespace XenonWZH {
const double EPS = 1e-9;

void solve() {
    int n;
    scanf("%d", &n);

    std::vector<int> x(n + 1), y(n + 1);
    for (int i = 1; i <= n; i++) scanf("%d %d", &x[i], &y[i]);

    int a, b, c;
    scanf("%d %d %d", &a, &b, &c);

    auto calc = [&](double xx) -> double {
        double ans = 0, yy = -(double)a / b * xx - (double)c / b;
        for (int i = 1; i <= n; i++) ans = std::max(ans, sqrt((xx - x[i]) * (xx - x[i]) + (yy - y[i]) * (yy - y[i])));
        return ans;
    };

    auto calcy = [&](double yy) -> double {
        double ans = 0, xx = -(double)c / a;
        for (int i = 1; i <= n; i++) ans = std::max(ans, sqrt((xx - x[i]) * (xx - x[i]) + (yy - y[i]) * (yy - y[i])));
        return ans;
    };

    if (b == 0) {
        double l = -1e4, r = 1e4;
        while (std::abs(r - l) > EPS) {
            double midL = l + (r - l) / 3, midR = l + (r - l) / 3 * 2;
            if (calcy(midL) > calcy(midR)) l = midL;
            else if (calcy(midL) < calcy(midR)) r = midR;
            else l = midL, r = midR;
        }
        printf("%lf\n", calcy(l));
    } else {
        double l = -1e4, r = 1e4;
        while (std::abs(r - l) > EPS) {
            double midL = l + (r - l) / 3, midR = l + (r - l) / 3 * 2;
            if (calc(midL) > calc(midR)) l = midL;
            else if (calc(midL) < calc(midR)) r = midR;
            else l = midL, r = midR;
        }
        printf("%.8lf\n", calc(l));
    }
}

int main() {
    int t;
    scanf("%d", &t);

    while (t--) solve();

    return 0;
}
};

int main() { return XenonWZH::main(); }