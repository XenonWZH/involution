#include <cstdio>
#include <iostream>

int main() {
    int t;

    scanf("%d", &t);

    while (t--) {
        int n, x, y;

        scanf("%d %d %d", &n, &x, &y);

        if (x == 0) std::swap(x, y);
        if ((x != 0 && y != 0) || (x == 0 && y == 0) || (n - 1) % x) {
            puts("-1");
            continue;
        }

        printf("1 ");
        int now = 1, cnt = 1;
        for (int i = 3; i <= n; i++) {
            cnt++;
            if (cnt > x) cnt = 1, now = i;
            printf("%d ", now);
        }
        putchar('\n');
    }

    return 0;
}