#include <cstdio>
#include <cmath>

int main() {
#ifndef DBG
    freopen("home.in", "r", stdin);
    freopen("home.out", "w", stdout);
#endif

    int x;

    scanf("%d", &x);

    printf("%.0f\n", ceil((sqrt(8.0 * x + 1) - 1) / 2.0));

#ifndef DBG
    fclose(stdin);
    fclose(stdout);
#endif

    return 0;
}