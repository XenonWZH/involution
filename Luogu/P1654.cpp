#include <cstdio>
#include <cstring>
#include <iostream>

const int MAXN = 100000;

int main() {
    int n;
    static double op[MAXN + 1];

    std::cin >> n;
    for (int i = 1; i <= n; i++) {
        std::cin >> op[i];
    }

    static double e1[MAXN + 1], e2[MAXN + 1], ans;
    e1[0] = e2[0] = ans = 0;

    for (int i = 1; i <= n; i++) {
        e1[i] = (e1[i - 1] + 1) * op[i];
        e2[i] = (e2[i - 1] + 2 * e1[i - 1] + 1) * op[i];
        ans += (3 * e2[i - 1] + 3 * e1[i - 1] + 1) * op[i]; 
    }

    printf("%.1lf\n", ans);

    return 0;
}