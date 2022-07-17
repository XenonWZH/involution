#include <cstdio>

int main() {
    int n, m, k;

    scanf("%d %d %d", &n, &m, &k);
    if (k == 2) m -= 2;

    for (int i = 0; i < m; i++) {
        putchar(i % 2 ? 'r' : 'l');
    }

    int cnt = 0;
    for (int i = m; i < n; i++) {
        cnt++;
        putchar(cnt % (k + 1) == 0 ? 'r' : 'l');
    }
    putchar('\n');

    return 0;
}