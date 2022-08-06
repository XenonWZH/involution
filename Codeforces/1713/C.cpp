#include <cstdio>
#include <cmath>

void solve(int n) {
    if (n < 0) return;
    long long tmp = pow(ceil(sqrt(n)), 2) - n;
    solve(tmp - 1);
    for (int i = n; tmp <= n; i--, tmp++) {
        printf("%d ", i);
    }
}

int main() {
    int t;

    scanf("%d", &t);

    while (t--) {
        int n;

        scanf("%d", &n);

        solve(n - 1);
        putchar('\n');
    }

    return 0;
}