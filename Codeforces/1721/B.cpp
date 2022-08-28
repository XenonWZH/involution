#include <cstdio>
#include <cmath>
#include <queue>

int main() {
    int t;

    scanf("%d", &t);

    while (t--) {
        int n, m, sx, sy, d;

        scanf("%d %d %d %d %d", &n, &m, &sx, &sy, &d);

        if (abs(n - sx) + abs(m - sy) <= d || (sx - d <= 1 && sy - d <= 1) || (sx + d >= n && sy + d >= m) || (sx - d <= 1 && sx + d >= n) || (sy - d <= 1 && sy + d >= m)) {
            puts("-1");
        } else printf("%d\n", n + m - 2);
    }

    return 0;
}