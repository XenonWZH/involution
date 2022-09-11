#include <cstdio>

int main() {
    int t;

    scanf("%d", &t);

    while (t--) {
        int a, b, c;
        scanf("%d %d %d", &a, &b, &c);

        for (int i = 1; i <= 2 * b + 2 * c + 1; i++) {
            if (i <= 2 * b) {
                for (int j = 1; j <= 2 * b + 1 - i; j++) putchar('.');
                for (int j = 1; j <= a; j++) printf(i % 2 ? "+-" : "/.");
                putchar(i % 2 ? '+' : '/');
            } else {
                for (int j = 1; j <= a; j++) printf(i % 2 ? "+-" : "|.");
                putchar(i % 2 ? '+' : '|');
            }
            if (i <= 2 * c) {
                if (i <= 2 * b) {
                    for (int j = 2 * a + 2 * b - i + 3; j < 2 * a + 2 * b + 1; j += 2) printf(i % 2 ? ".+" : "|/");
                    if (i % 2 == 0) putchar('|');
                } else for (int j = 1; j <= b; j++) printf(i % 2 ? ".+" : "/|");
            } else {
                if (i >= 2 * b + 1) {
                    for (int j = 1; j <= (2 * b + 2 * c + 1 - i) / 2; j++) printf(i % 2 ? ".+" : "/|");
                    if (i % 2 == 0) putchar('/');
                    for (int j = (2 * b + 2 * c + 1 - i) / 2 * 2 + 2 * a + (i + 1) % 2 + 2; j <= 2 * a + 2 * b + 1; j++) putchar('.');
                } else {
                    for (int j = 1; j <= c; j++) printf(i % 2 ? ".+" : "|/");
                    for (int j = 2 * a + 2 * b + 2 * c - i + 3; j <= 2 * a + 2 * b + 1; j++) putchar('.');
                }
            }
            putchar('\n');
        }
    }

    return 0;
}