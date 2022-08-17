#include <cstdio>

int main() {
    int t;

    scanf("%d", &t);

    while (t--) {
        int n, k;

        scanf("%d %d", &n, &k);

        if (k % 4 == 0) {
            puts("NO");
            continue;
        }

        puts("YES");
        if (k % 2 == 1) {
            for (int i = 1; i <= n; i += 2) {
                if (n - i >= 1) printf("%d %d\n", i, i + 1);
            }
        } else {
            for (int i = 1; i <= n; i += 4) {
                if (n - i >= 1)printf("%d %d\n", i + 1, i);
                if (n - i >= 3) printf("%d %d\n", i + 2, i + 3);
            }
        }
    }

    return 0;
}