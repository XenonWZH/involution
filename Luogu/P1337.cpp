#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>

const int MAXN = 100000;

int n, x[MAXN + 1], y[MAXN + 1], w[MAXN + 1];
double ansx, ansy, dis;

double myRand() {
    return (double)rand() / RAND_MAX;
}

double calc(double xx, double yy) {
    double res = 0;
    for (int i = 1; i <= n; i++) {
        double dx = x[i] - xx, dy = y[i] - yy;
        res += sqrt(dx * dx + dy * dy) * w[i];
    }
    if (res < dis) dis = res, ansx = xx, ansy = yy;
    return res;
}

void simulateAnneal() {
    double t = 100000;
    double nowx = ansx, nowy = ansy;
    while (t > 0.001) {
        double nxtx = nowx + t * (myRand() * 2 - 1);
        double nxty = nowy + t * (myRand() * 2 - 1);
        double delta = calc(nxtx, nxty) - calc(nowx, nowy);
        if (exp(-delta / t) > myRand()) nowx = nxtx, nowy = nxty;
        t *= 0.97;
    }
    for (int i = 1; i <= 1000; i++) {
        double nxtx = ansx + t * (myRand() * 2 - 1);
        double nxty = ansy + t * (myRand() * 2 - 1);
        calc(nxtx, nxty);
    }
}

int main() {
    srand(time(nullptr));

    scanf("%d", &n);

    for (int i = 1; i <= n; i++) {
        scanf("%d %d %d", &x[i], &y[i], &w[i]);
        ansx += x[i], ansy += y[i];
    }

    ansx /= n, ansy /= n, dis = calc(ansx, ansy);
    simulateAnneal();

    printf("%.3f %.3f\n", ansx, ansy);

    return 0;
}
