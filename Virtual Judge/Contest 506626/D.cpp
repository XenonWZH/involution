#include <bits/stdc++.h>

const int MAXN = 800;

int gcd(int a, int b) {
    return b ? gcd(b, a % b) : a;
}

int main() {
    int n;
    static int a[MAXN], b[MAXN];

    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }
    for (int i = 0; i < n; i++) {
        scanf("%d", &b[i]);
    }

    static long long sum[MAXN];
    sum[0] = b[0];
    for (int i = 1; i < n; i++) {
        sum[i] = sum[i - 1] + b[i];
    }

    static int f[MAXN][MAXN];
    for (int i = 0; i < n - 1; i++) {
        if (gcd(a[i], a[i + 1]) != 1) {
            f[i][i + 1] = 1;
        }
    }

    for (int len = 3; len <= n; len++) {
        for (int l = 0; l + len - 1 < n; l++) {
            int r = l + len - 1;
            if (gcd(a[l], a[r]) != 1) f[l][r] = std::max(f[l][r], f[l + 1][r - 1]);

            for (int k = l + 1; k < r - 1; k++) {
                f[l][r] = std::max(f[l][r], f[l][k] * f[k + 1][r]);
            }
        }
    }

    static long long dp[MAXN];
    for (int i = 0; i < n; i++) {
        if (i) dp[i] = dp[i - 1];
        for (int j = 0; j < i; j++) {
            if (f[j][i]) {
                dp[i] = std::max(dp[i], dp[j - 1] + sum[i] - sum[j - 1]);
            }
        }
    }

    printf("%lld\n", dp[n - 1]);

    return 0;
}