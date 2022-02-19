#include <cstdio>
#include <cstring>
#include <iostream>

const int MAXN = 300, INF = 0x3f3f3f3f;

int n, a[MAXN + 1];
int f[MAXN + 1][MAXN + 1];

int dp(int l, int r) {
    if (f[l][r] != INF) return f[l][r];

    for (int i = l; i < r; i++) {
        f[l][r] = std::min(f[l][r], dp(l, i) + dp(i + 1, r) + a[r] - a[l - 1]);
    }

    return f[l][r];
}

int main() {
    std::cin >> n;
    for (int i = 1; i <= n; i++) {
        scanf("%d", &a[i]);
        a[i] += a[i - 1];
    }

    memset(f, 0x3f, sizeof(f));
    for (int i = 1; i <= n; i++) f[i][i] = 0;

    std::cout << dp(1, n) << std::endl;

    return 0;
}