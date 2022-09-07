#include <cstdio>

int main() {
    int t;

    scanf("%d", &t);

    while (t--) {
        int n, m;

        scanf("%d %d", &n, &m);

        if (n > m) {
            puts("No");
            continue;
        }
        if (n == 0) {
            puts(m == 0 ? "Yes" : "No");
            continue;
        }

        if (n % 2 == 1) {
            puts("Yes");
            for (int i = 1; i <= n - 1; i++) printf("1 ");
            printf("%d\n", m - n + 1);
        } else {
            if (m % 2 == 0) {
                puts("Yes");
                for (int i = 1; i <= n - 2; i++) printf("1 ");
                printf("%d %d\n", (m - n + 2) / 2, (m - n + 2) / 2);
            } else {
                puts("No");
                continue;
            }
        }
    }

    return 0;
}