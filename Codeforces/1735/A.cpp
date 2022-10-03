#include <cstdio>
#include <iostream>

void solve() {
    int n;

    scanf("%d", &n);

    printf("%d\n", n / 3 - 2);
    printf("%d\n", ((n - 2) / 3) - 2);
}

int main() {
    int t;

    scanf("%d", &t);

    while (t--) solve();

    return 0;
}