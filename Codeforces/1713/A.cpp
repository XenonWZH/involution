#include <cstdio>
#include <climits>
#include <algorithm>

int main() {
    int t;

    scanf("%d", &t);

    while (t--) {
        int n;

        scanf("%d", &n);

        int minX = 0, maxX = 0, minY = 0, maxY = 0;
        for (int i = 0; i < n; i++) {
            int x, y;
            scanf("%d %d", &x, &y);
            minX = std::min(minX, x);
            maxX = std::max(maxX, x);
            minY = std::min(minY, y);
            maxY = std::max(maxY, y);
        }

        printf("%d\n", 2 * (maxX - minX + maxY - minY));
    }

    return 0;
}