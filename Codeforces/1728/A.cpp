#include <cstdio>
#include <iostream>

const int MAXN = 20;

int main() {
    int t;

    scanf("%d", &t);

    while (t--) {
        int n;
        static int a[MAXN + 1];

        scanf("%d", &n);

        int max = 1;
        for (int i = 1; i <= n; i++) {
            scanf("%d", &a[i]);
            if (a[i] > a[max]) max = i;
        }

        printf("%d\n", max);
    }

    return 0;
}