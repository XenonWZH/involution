#include <bits/stdc++.h>

void solve() {
    int n;
    scanf("%d", &n);

    printf("1 ");
    for (int i = n; i >= 2; i--) printf("%d ", i);
    putchar('\n');
}

int main() {
    int t;

    scanf("%d", &t);

    while (t--) solve();

    return 0;
}