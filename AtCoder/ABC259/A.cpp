#include <cstdio>

int main() {
    int n, m, x, t, d;

    scanf("%d %d %d %d %d", &n, &m, &x, &t, &d);

    int first = t - x * d;

    if (m <= x) printf("%d\n", first + m * d);
    else printf("%d\n", t);

    return 0;
}