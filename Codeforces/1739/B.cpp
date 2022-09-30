#include <cstdio>
#include <iostream>

const int MAXN = 100;

void solve() {
    int n;
    static int d[MAXN + 1];

    scanf("%d", &n);
    for (int i = 1; i <= n; i++) scanf("%d", &d[i]);

    static int a[MAXN + 1];
    a[1] = d[1];
    for (int i = 2; i <= n; i++) {
        if (a[i - 1] - d[i] >= 0 && d[i] != 0) {
            puts("-1");
            return;
        } else a[i] = a[i - 1] + d[i];
    }

    for (int i = 1; i <= n; i++) printf("%d ", a[i]);
    putchar('\n');
}

int main() {
    int t;

    scanf("%d", &t);

    while (t--) solve();

    return 0;
}