#include <cstdio>

int main() {
    int t;

    scanf("%d", &t);

    while (t--) {
        int n, m;

        scanf("%d %d", &n, &m);

        if (n == 1 && m == 1) {
            puts("0");
            continue;
        }

        if (n < m) printf("%d\n", 2 * n + m - 2);
        else printf("%d\n", 2 * m + n - 2);
    }

    return 0;
}