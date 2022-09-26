#include <cstdio>
#include <iostream>

const int MAXN = 100;

void solve() {
    int n, c;
    static int a[MAXN + 1];

    scanf("%d %d", &n, &c);
    for (int i = 1; i <= 100; i++) a[i] = 0;
    for (int i = 1; i <= n; i++) {
        int in;
        scanf("%d", &in);
        a[in]++;
    }

    int ans = 0;
    for (int i = 1; i <= 100; i++) ans += std::min(a[i], c);

    printf("%d\n", ans);
}

int main() {
    int t;

    scanf("%d", &t);

    while (t--) solve();

    return 0;
}