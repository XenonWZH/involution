#include <cstdio>

const int MAXN = 200000;

int main() {
    int t;

    scanf("%d", &t);

    while (t--) {
        int n, minNum = 1e6 + 1;
        static int a[MAXN];

        scanf("%d", &n);
        for (int i = 0; i < n; i++) {
            scanf("%d", &a[i]);
            if (a[i] < minNum) minNum = a[i];
        }

        for (int i = 0, cnt = 0; i < n / 2; i++, cnt++) {
            if (a[cnt] == minNum) {
                i--;
                continue;
            }
            printf("%d %d\n", a[cnt], minNum);
        }
    }

    return 0;
}