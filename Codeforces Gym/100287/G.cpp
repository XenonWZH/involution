#include <cstdio>
#include <cmath>
#include <iostream>

int main() {
    freopen("graveyard.in", "r", stdin);
    freopen("graveyard.out", "w", stdout);

    int n, m;

    while (scanf("%d %d", &n, &m) != EOF) {
        double ans = 0;
        for (int i = 1; i < n; i++) {
            double pos = i * 1.0 / n  * (n + m);
            ans += std::abs(pos - floor(pos + 0.5)) / (n + m);
        }

        printf("%.4lf\n", ans * 10000);
    }

    fclose(stdin);
    fclose(stdout);

    return 0;
}