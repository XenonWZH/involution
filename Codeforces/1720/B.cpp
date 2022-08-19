#include <cstdio>
#include <algorithm>

const int MAXN = 1e5;

int main() {
    int t;

    scanf("%d", &t);

    while (t--) {
        int n;
        static int a[MAXN + 1];

        scanf("%d", &n);
        for (int i = 1; i <= n; i++) {
            scanf("%d", &a[i]);
        }

        std::sort(a + 1, a + n + 1);

        printf("%d\n", a[n] + a[n - 1] - a[1] - a[2]);
    }

    return 0;
}