#include <cstdio>

int main() {
    int t;

    scanf("%d", &t);
    
    while (t--) {
        int x, a[4];

        scanf("%d", &x);
        scanf("%d %d %d", &a[1], &a[2], &a[3]);

        if (a[x] == 0 || a[1] == 1 || a[2] == 2 || a[3] == 3) puts("NO");
        else puts("YES");
    }

    return 0;
}