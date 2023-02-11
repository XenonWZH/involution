#include <cstdio>

const int MAXN = 500000;

int main() {
    int k;
    scanf("%d", &k);

    static int a[MAXN + 1];
    for (int i = 1; i <= k; i++) {
        scanf("%d", &a[i]);
        a[0] ^= a[i];
    }

    if (a[0]) {
        for (int i = 1; i <= k; i++) {
            if ((a[i] ^ a[0]) <= a[i]) {
                printf("%d %d\n", a[i] - (a[i] ^ a[0]), i);
                a[i] ^= a[0];
                break;
            }
        }
        for (int i = 1; i <= k; i++) printf("%d ", a[i]);
        puts("");
    } else puts("lose");

    return 0;
}