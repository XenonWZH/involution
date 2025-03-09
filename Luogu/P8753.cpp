#include <bits/stdc++.h>

int main() {
    int n;
    scanf("%d", &n);

    int ans = 0;
    for (int i = 1; i <= n - 1; i++) {
        if (i * i % n <= n / 2) ans++;
    }

    printf("%d\n", ans);

    return 0;
}