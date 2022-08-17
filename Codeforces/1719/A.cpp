#include <cstdio>

int main() {
    int t;

    scanf("%d", &t);

    while (t--) {
        int n, m;

        scanf("%d %d", &n, &m);

        if (n % 2 == 1 && m % 2 == 1) puts("Tonya");
        else if (n % 2 == 1 && m % 2 == 0) puts("Burenka");
        else if (n % 2 == 0 && m % 2 == 1) puts("Burenka");
        else puts("Tonya");
    }

    return 0;
}