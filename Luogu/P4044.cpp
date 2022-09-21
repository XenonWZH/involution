#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <ctime>
#include <iostream>

const int MAXN = 50;

int n, rounds;
std::pair<int, int> a[MAXN + 1];
int ans = 0;

int calc() {
    int res = 0;
    for (int i = 0; i < rounds; i++) {
        res += a[i].first + a[i].second;
        if (i < n) {
            if (a[i].first == 10) res += a[i + 1].first + a[i + 1].second;
            else if (a[i].first + a[i].second == 10) res += a[i + 1].first;
        }
    }
    ans = std::max(ans, res);
    return res;
}

void simulateAnneal() {
    for (double t = 1e4; t > 1e-4; t *= 0.99) {
        int x = rand() % rounds, y = rand() % rounds;
        int bef = calc();
        std::swap(a[x], a[y]);
        if (n + (a[n - 1].first == 10) == rounds) {
            int aft = calc();
            int delta = aft - bef;
            if (exp(delta / t) < (double)rand() / RAND_MAX) std::swap(a[x], a[y]);
        } else std::swap(a[x], a[y]);
    }
}

int main() {
    scanf("%d", &n);
    for (int i = 0; i < n; i++) scanf("%d %d", &a[i].first, &a[i].second);
    if (a[n - 1].first == 10) {
        scanf("%d %d", &a[n].first, &a[n].second);
        rounds = n + 1;
    } else rounds = n;

    while ((double)clock() / CLOCKS_PER_SEC < 0.8) simulateAnneal();

    printf("%d\n", ans);

    return 0;
}