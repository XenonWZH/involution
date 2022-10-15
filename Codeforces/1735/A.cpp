#include <cstdio>

void solve() {
    int n;

    scanf("%d", &n);

    printf("%d\n", n / 3 - 2);
}

int main() {
    int t;

    scanf("%d", &t);

    while (t--) solve();

    return 0;
}