#include <cstdio>

const int MAXN = 100;

int main() {
    int t;

    scanf("%d", &t);

    while (t--) {
        int n, k;
        static int a[MAXN + 1];

        scanf("%d %d", &n, &k);

        int counts = 0;
        for (int i = 1; i <= n; i++) {
            scanf("%d", &a[i]);
            if (a[i] > k && i <= k) counts++;
        }

        printf("%d\n", counts);
    }

    return 0;
}