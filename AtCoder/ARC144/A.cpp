#include <cstdio>

int main() {
    int n;

    scanf("%d", &n);

    printf("%d\n", 2 * n);
    if (n % 4) putchar(n % 4 + '0');
    for (int i = 0; i < n / 4; i++) putchar('4');
    putchar('\n');

    return 0;
}