#include <bits/stdc++.h>

void solve() {
    int n;
    scanf("%d", &n);

    if (n & 1) {
        printf("%d ", n);
        n--;
    }

    for (int i = n / 2; i >= 1; i--) printf("%d %d ", i, (n + 1) / 2 + i);
    putchar('\n');
}

int main() {
    int t;

    scanf("%d", &t);

    while (t--) solve();

    return 0;
}