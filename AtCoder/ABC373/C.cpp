#include <bits/stdc++.h>

int main() {
    int n;
    scanf("%d", &n);

    int a = -INT_MIN;
    for (int i = 1; i <= n; i++) {
        int x;
        scanf("%d", &x);
        a = std::max(a, x);
    }
    int b = -INT_MIN;
    for (int i = 1; i <= n; i++) {
        int x;
        scanf("%d", &x);
        b = std::max(b, x);
    }

    printf("%lld\n", (long long)a + b);

    return 0;
}