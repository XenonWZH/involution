#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <iostream>

const int MAXN = 100;
const int MAXX = 10000;

int n;
std::pair<double, double> q[MAXN + 1];
double ans = 1e8;

double rand(double l, double r) {
    return rand() * 1.0 / RAND_MAX * (r - l) + l;
}

double dist(std::pair<double, double> a, std::pair<double, double> b) {
    return std::sqrt((a.first - b.first) * (a.first - b.first) + (a.second - b.second) * (a.second - b.second));
}

double calc(std::pair<double, double> p) {
    double res = 0;
    for (int i = 1; i <= n; i++) res += dist(p, q[i]);
    ans = std::min(ans, res);
    return res;
}

void simulateAnneal() {
    std::pair<double, double> cur = std::make_pair(rand(0, MAXX), rand(0, MAXX));
    for (double t = MAXX; t > 1e-4; t *= 0.99) {
        std::pair<double, double> np = std::make_pair(rand(cur.first - t, cur.first + t),
                                                      rand(cur.second - t, cur.second + t));
        double dt = calc(np) - calc(cur);
        if (exp(-dt / t) > rand(0, 1)) cur = np;
    }
}

int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) scanf("%lf %lf", &q[i].first, &q[i].second);

    for (int i = 1; i <= 50; i++) simulateAnneal();

    printf("%.0f", ans);

    return 0;
}