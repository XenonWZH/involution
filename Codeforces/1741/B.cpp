#include <bits/stdc++.h>

void solve() {
    int n;

    scanf("%d", &n);

    if (n == 3) {
        puts("-1");
        return;
    }

    if (n % 2 == 0) for (int i = n; i >= 1; i--) printf("%d ", i);
    else {
        printf("%d %d ", n, n - 1);
        for (int i = 1; i <= n - 2; i++) printf("%d ", i);
    }
    putchar('\n');
}

int main() {
    int t;

    scanf("%d", &t);

    while (t--) solve();

    return 0;
}