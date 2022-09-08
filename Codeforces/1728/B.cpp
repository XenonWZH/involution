#include <cstdio>

int main() {
    int t;

    scanf("%d", &t);

    while (t--) {
        int n;
        scanf("%d", &n);

        if (n <= 3) {
            for (int i = 1; i <= n; i++) printf("%d ", i);
            putchar('\n');
            continue;
        }

        if (n % 2 == 0) {
            for (int i = n - 2; i >= 2; i--) printf("%d ", i);
            printf("%d %d %d\n", 1, n - 1, n);
        } else {
            for (int i = n - 1; i >= 2; i--) {
                if (i == n - 2) continue;
                printf("%d ", i);
            }
            printf("%d %d %d\n", 1, n - 2, n);
        }
    }

    return 0;
}