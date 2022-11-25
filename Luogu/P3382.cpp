#include <cstdio>
#include <vector>

const double EPS = 1e-6;

int main() {
    int n;
    double l, r;
    scanf("%d %lf %lf", &n, &l, &r);

    std::vector<double> a(n + 1);
    for (int i = n; i >= 0; i--) scanf("%lf", &a[i]);

    auto calc = [&](double x) {
        double ans = 0, res = 1;
        for (int i = 0; i <= n; i++) {
            ans += res * a[i];
            res *= x;
        }
        return ans;
    };

    while (r - l > EPS) {
        double midL = l + (r - l) / 3, midR = l + (r - l) / 3 * 2;
        if (calc(midL) < calc(midR)) l = midL;
        else if (calc(midL) > calc(midR)) r = midR;
        else if (calc(midL) == calc(midR)) l = midL, r = midR;
    }

    printf("%.5f\n", l);

    return 0;
}