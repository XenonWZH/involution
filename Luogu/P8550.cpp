#include <cstdio>
#include <iostream>

const int MAXN = 5;

void solve() {
    int n, x;
    static int a[MAXN + 1];

    scanf("%d %d", &n, &x);
    for (int i = 1; i <= n; i++) scanf("%d", &a[i]);

    for (int i = 1; i <= n; i++) {
        if (x % a[i] != 0 || x * a[i] > 0) {
            puts("Yes");
            return;
        }
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (i == j) continue;
            if (a[i] > a[j] && a[i] % a[j] != 0) {
                puts("Yes");
                return;
            }
        }
    }

    puts("No");
}

int main() {
    int t;

    scanf("%d", &t);

    while (t--) solve();

    return 0;
}