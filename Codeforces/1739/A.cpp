#include <cstdio>
#include <iostream>

void solve() {
    int n, m;
    scanf("%d %d", &n, &m);

    if ((n >= 2 && m >= 4) || (n >= 4 && m >= 2)) puts("1 1");
    else if (n == 1 || m == 1) puts("1 1");
    else printf("%d %d\n", (n + 1) / 2, (m + 1) / 2);
}

int main() {
    int t;

    scanf("%d", &t);

    while (t--) solve();

    return 0;
}