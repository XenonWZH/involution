#include <cstdio>
#include <algorithm>

const int MAXN = 1e5;

int main() {
    int n, k;

    scanf("%d %d", &n, &k);
    k--;

    static int a[MAXN];
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }
    std::sort(a, a + n);

    static int diff[MAXN];
    for (int i = 0; i < n - 1; i++) {
        diff[i] = a[i + 1] - a[i] - 1;
    }
    std::sort(diff, diff + n - 1);

    int ans = a[n - 1] + 1;
    for (int i = n - 2; i >= std::max(0, n - k - 1); i--) {
        ans -= diff[i];
    }

    printf("%d\n", ans - a[0]);

    return 0;
}