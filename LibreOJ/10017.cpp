#include <cmath>
#include <iostream>
#include <utility>

double ax, ay, bx, by;
double cx, cy, dx, dy;
double p, q, rr;

double dis(std::pair<double, double> a, std::pair<double, double> b) {
    return sqrt(pow(a.first - b.first, 2) + pow(a.second - b.second, 2));
}

double solveCD(double x, double y) {
    std::pair<double, double> l = std::make_pair(cx, cy), r = std::make_pair(dx, dy);
    std::pair<double, double> lMid, rMid;
    double lVal = -100, rVal = dis(std::make_pair(ax, ay), std::make_pair(dx, dy)) / rr;

    while (abs(rVal - lVal) >= 0.000001) {
        lMid = std::make_pair(l.first + (r.first - l.first) / 3.0, l.second + (r.second - l.second) / 3.0);
        rMid = std::make_pair(l.first + (r.first - l.first) / 1.5, l.second + (r.second - l.second) / 1.5);
        lVal = dis(lMid, std::make_pair(x, y)) / rr + dis(lMid, std::make_pair(dx, dy)) / q;
        rVal = dis(rMid, std::make_pair(x, y)) / rr + dis(rMid, std::make_pair(dx, dy)) / q;

        if (lVal > rVal) l = lMid;
        if (lVal < rVal) r = rMid;
        if (lVal == rVal) l = lMid, r = rMid;
    }

    return lVal;
}

double solveAB() {
    std::pair<double, double> l = std::make_pair(ax, ay), r = std::make_pair(bx, by);
    std::pair<double, double> lMid, rMid;
    double lVal = -100, rVal = dis(std::make_pair(ax, ay), std::make_pair(bx, by)) / p;

    while (abs(rVal - lVal) >= 0.000001) {
        lMid = std::make_pair(l.first + (r.first - l.first) / 3.0, l.second + (r.second - l.second) / 3.0);
        rMid = std::make_pair(l.first + (r.first - l.first) / 1.5, l.second + (r.second - l.second) / 1.5);
        lVal = dis(lMid, std::make_pair(ax, ay)) / p + solveCD(lMid.first, lMid.second);
        rVal = dis(rMid, std::make_pair(ax, ay)) / p + solveCD(rMid.first, rMid.second);

        if (lVal > rVal) l = lMid;
        if (lVal < rVal) r = rMid;
        if (lVal == rVal) l = lMid, r = rMid;
    }

    return lVal;
}

int main() {
    std::cin >> ax >> ay >> bx >> by;
    std::cin >> cx >> cy >> dx >> dy;
    std::cin >> p >> q >> rr;

    printf("%.2f\n", solveAB());

    return 0;
}