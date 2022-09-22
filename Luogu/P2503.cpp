#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <cstring>
#include <iostream>
#include <algorithm>

const int MAXN = 25;
const int MAXM = 10;

int n, m;
int w[MAXN], s[MAXM];
double ans = 1e8;

double calc() {
    memset(s, 0, sizeof(s));
    for (int i = 0; i < n; i++) {
        int k = 0;
        for (int j = 0; j < m; j++)
            if (s[j] < s[k]) k = j;
        s[k] += w[i];
    }

    double avg = 0;
    for (int i = 0; i < m; i++) avg += (double)s[i] / m;
    double res = 0;
    for (int i = 0; i < m; i++) res += (s[i] - avg) * (s[i] - avg);
    res = sqrt(res / m);
    ans = std::min(ans, res);
    return res;
}

void simulate_anneal() {
    std::random_shuffle(w, w + n);

    for (double t = 1e6; t > 1e-6; t *= 0.95) {
        int a = rand() % n, b = rand() % n;
        double x = calc();
        std::swap(w[a], w[b]);
        double y = calc();
        double delta = y - x;
        if (exp(-delta / t) < (double)rand() / RAND_MAX) std::swap(w[a], w[b]);
    }
}

int main() {
    scanf("%d %d", &n, &m);
    for (int i = 0; i < n; i++) scanf("%d", &w[i]);

    while ((double)clock() / CLOCKS_PER_SEC < 0.8) simulate_anneal();

    printf("%.2f\n", ans);

    return 0;
}