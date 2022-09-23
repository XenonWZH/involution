#include <cstdio>
#include <iostream>

inline void solve() {
    int n;

    scanf("%d", &n);

    puts("1");
    for (int i = 2; i <= n; i++) {
        printf("1 ");
        for (int j = 2; j <= i - 1; j++) printf("0 ");
        puts("1");
    }
}

int main() {
    int t;

    scanf("%d", &t);

    while (t--) solve();

    return 0;
}