#include <cstdio>

const int MAXN = 100;

int main() {
    int n;
    scanf("%d", &n);

    long long ans = 0;
    static bool vis[2 * MAXN + 100][2 * MAXN + 100];
    while (n--) {
        int x, y;
        scanf("%d %d", &x, &y);
        if (!vis[2 * x - 1][2 * y]) vis[2 * x - 1][2 * y] = true, ans++;
        if (!vis[2 * x + 1][2 * y]) vis[2 * x + 1][2 * y] = true, ans++;
        if (!vis[2 * x][2 * y - 1]) vis[2 * x][2 * y - 1] = true, ans++;
        if (!vis[2 * x][2 * y + 1]) vis[2 * x][2 * y + 1] = true, ans++;
    }

    printf("%.1f", ans / 2.0);

    return 0;
}