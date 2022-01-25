#include <cstdio>
#include <cmath>

void printAns(int x, int y) {
    if (x == y) puts("=");
    if (x < y) puts("<");
    if (x > y) puts(">");
}

int main() {
    int t;

    scanf("%d", &t);

    while (t--) {
        int x1, p1, x2, p2;

        scanf("%d%d%d%d", &x1, &p1, &x2, &p2);

        int len1 = log10(x1), len2 = log10(x2);
        if (len1 + p1 == len2 + p2) {
            if (len1 < len2) {
                for (int i = len1; i < len2; i++) x1 *= 10;
                printAns(x1, x2);
            } else {
                for (int i = len2; i < len1; i++) x2 *= 10;
                printAns(x1, x2);
            }
        } else printAns(len1 + p1, len2 + p2);
    }

    return 0;
}