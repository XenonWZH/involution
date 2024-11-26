#include <cstdio>

int main() {
    int n;
    scanf("%d", &n);

    int ans = 0;
    for (int i = 1; i <= n; i++) {
        int x = i;
        bool odd = true, con = true;
        while (x) {
            if (x % 2 != odd) {
                con = false;
                break;
            }
            odd ^= 1, x /= 10;
        }
        if (con) ans++;
    }

    printf("%d\n", ans);

    return 0;
}