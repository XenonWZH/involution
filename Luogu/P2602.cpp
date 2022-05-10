#include <cstdio>

const int MAXN = 15, MOD = 10000007;

long long dp[MAXN], ansl[MAXN], ansr[MAXN], power[MAXN];
int a[MAXN];

inline void solve(long long n, long long *ans) {
    long long tmp = n;
    int len = 0;
    while (n) {
        a[++len] = n % 10;
        n /= 10;
    }
    for (int i = len; i >= 1; i--) {
        for (int j = 0; j < 10; j++) ans[j] += dp[i - 1] * a[i];
        for (int j = 0; j < a[i]; j++) ans[j] += power[i - 1];
        tmp -= power[i - 1] * a[i], ans[a[i]] += tmp + 1;
        ans[0] -= power[i - 1];
    }
}

int main() {
    long long l, r;

    scanf("%lld %lld", &l, &r);

    power[0] = 1;
    for (int i = 1; i < MAXN; i++) {
        dp[i] = dp[i - 1] * 10 + power[i - 1];
        power[i] = power[i - 1] * 10;
    }

    solve(l - 1, ansl);
    solve(r, ansr);

    for (int i = 0; i < 10; i++) {
        printf("%lld ", ansr[i] - ansl[i]);
    }

    return 0;
}