#include <cstdio>
#include <cmath>
#include <iostream>

struct Point {
    double x, y;

    Point() {}
    Point(double x, double y) : x(x), y(y) {}
};

struct Line {
    double k, b;

    Line(Point u, Point v) { calcPoint(u, v); }
    Line(double k, double b) : k(k), b(b) {}

    void calcPoint(Point u, Point v) {
        k = (u.y - v.y) / (u.x - v.x);
        b = u.y - k * u.x;
    }

    Line getVertical(Point u) { return Line(-1 / k, u.x / k + u.y); }
};

inline double distance(Point a, Point b) { return sqrt((a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y)); }
inline double distance(Point a, Line b) { return std::abs(b.k * a.x - a.y + b.b) / sqrt(b.k * b.k + 1); }
inline Point intersectPoint(Line a, Line b) { return Point((b.b - a.b) / (a.k - b.k), (b.b - a.b) / (a.k - b.k) * a.k + a.b); }

void solve() {
    Point p1, p2, p3;
    double r;
    scanf("%lf %lf %lf %lf %lf %lf %lf", &p1.x, &p1.y, &p2.x, &p2.y, &p3.x, &p3.y, &r);

    if (p1.x == p2.x) {
        if (p3.y >= std::min(p1.y, p2.y) && p3.y <= std::max(p1.y, p2.y)) printf("%.2f ", std::abs(p3.x - p1.x) - r);
        else printf("%.2f ", std::min(distance(p1, p3), distance(p2, p3)) - r);
    } else if (p1.y == p2.y) {
        if (p3.x >= std::min(p1.x, p2.x) && p3.x <= std::max(p1.x, p2.x)) printf("%.2f ", std::abs(p3.y - p1.y) - r);
        else printf("%.2f ", std::min(distance(p1, p3), distance(p2, p3)) - r);
    } else {
        Line way(p1, p2);
        double dis = distance(p3, way);
        Line ver = way.getVertical(p3);
        Point inter = intersectPoint(way, ver);

        if (inter.x >= std::min(p1.x, p2.x) && inter.x <= std::max(p1.x, p2.x) &&
            inter.y >= std::min(p1.y, p2.y) && inter.y <= std::max(p1.y, p2.y)) printf("%.2f ", dis - r);
        else printf("%.2f ", std::min(distance(p1, p3), distance(p2, p3)) - r);
    }

    printf("%.2f\n", std::max(distance(p1, p3), distance(p2, p3)) + r);
}

int main() {
    int t;

    scanf("%d", &t);

    while (t--) solve();

    return 0;
}