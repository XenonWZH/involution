#include <cstdio>
#include <cstring>
#include <algorithm>

const int MAXN = 800;

long long gcd(long long a, long long b) {
    return b == 0 ? a : gcd(b, a % b);
}

int main() {
    int n;
    static long long a[MAXN + 1], b[MAXN + 1];

    scanf("%d", &n);
    for (int i = 1; i <= n; i++) scanf("%lld", &a[i]);
    for (int i = 1; i <= n; i++) scanf("%lld", &b[i]);

    static long long f[MAXN + 1][MAXN + 1];
    memset(f, 0xcf, sizeof(f));
    for (int i = 1; i <= n - 1; i++) {
        if (gcd(a[i], a[i + 1]) != 1) {
            f[i][i + 1] = b[i] + b[i + 1];
        }
    }

    for (int len = 4; len <= n; len += 2) {
        for (int l = 1; l + len - 1 <= n; l++) {
            int r = l + len - 1;
            if (gcd(a[l], a[r]) != 1) f[l][r] = f[l + 1][r - 1] + b[l] + b[r];
            for (int k = l + 1; k <= r - 1; k += 2) f[l][r] = std::max(f[l][r], f[l][k] + f[k + 1][r]);
        }
    }

    static long long dp[MAXN + 1];
    for (int i = 2; i <= n; i++) {
        dp[i] = dp[i - 1];
        for (int j = 0; j <= i - 1; j++) dp[i] = std::max(dp[i], dp[j] + f[j + 1][i]);
    }

    printf("%lld\n", dp[n]);

    return 0;
}