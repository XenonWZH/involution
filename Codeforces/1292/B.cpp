#include <cstdio>
#include <cmath>
#include <vector>

int main() {
    long long x0, y0, ax, ay, bx, by;
    long long xs, ys, t;
    scanf("%lld %lld %lld %lld %lld %lld", &x0, &y0, &ax, &ay, &bx, &by);
    scanf("%lld %lld %lld", &xs, &ys, &t);

    long long xl = xs + t, yl = ys + t;
    using Point = std::pair<long long, long long>;
    auto dist = [](Point a, Point b) {
        return std::abs(a.first - b.first) + std::abs(a.second - b.second);
    };

    std::vector<Point> points;
    while (x0 <= xl && y0 <= yl) {
        points.emplace_back(x0, y0);
        x0 = ax * x0 + bx;
        y0 = ay * y0 + by;
    }

    int n = points.size();
    int ans = 0;
    for (int i = 0; i < n; i++) {
        for (int j = i; j < n; j++) {
            long long len = dist(points[i], points[j]);
            long long left = dist(points[i], {xs, ys});
            long long right = dist(points[j], {xs, ys});
            if (len + left <= t || len + right <= t) ans = std::max(ans, j - i + 1);
        }
    }

    printf("%d\n", ans);

    return 0;
}