#include <bits/stdc++.h>

int main() {
    int n;
    scanf("%d", &n);

    int ans = 0;
    for (int i = 1; i <= n; i++) {
        unsigned long long x;
        scanf("%llu", &x);
        if (__builtin_popcountll(x) == 1) ans++;
    }

    printf("%d\n", ans);

    return 0;
}