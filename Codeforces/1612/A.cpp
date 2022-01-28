#include <cstdio>

inline int myAbs(int x) {
    return x > 0 ? x : -x;
}

int main() {
    int t;

    scanf("%d", &t);

    while (t--) {
        int x, y;

        scanf("%d%d", &x, &y);

        if ((x % 2 == 0 && y % 2 != 0) || (x % 2 != 0 && y % 2 == 0)) printf("-1 -1\n");
        else if (x * y % 2 == 0) printf("%d %d\n", x / 2, y / 2);
        else printf("%d %d\n", x / 2, y / 2 + 1);
    }

    return 0;
}