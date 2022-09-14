#include <cstdio>

const int MAXN = 20;
const int MOD = 1e9 + 7;

long long a[MAXN + 1], m, ans = 0;
int inv[MAXN + 1], n;

inline int power(int a, int b) {
    int c = 1;
    for (; b; b >>= 1) {
        if (b & 1) c = (long long)c * a % MOD;
        a = (long long)a * a % MOD;
    }
    return c;
}

int C(long long y, int x) {
    if (y < 0 || x < 0 || y < x) return 0;
    y %= MOD;
    if (y == 0 || x == 0) return 1;
    int ans = 1;
    for (int i = 0; i < x; i++) ans = (long long)ans * (y - i) % MOD;
    for (int i = 1; i <= x; i++) ans = (long long)ans * inv[i] % MOD;
    return ans;
}

int main() {
    for (int i = 1; i <= MAXN; i++) inv[i] = power(i, MOD - 2);
    scanf("%d %lld", &n, &m);
    for (int i = 1; i <= n; i++) scanf("%lld", &a[i]);
    for (int x = 0; x < (1 << n); x++) {
        if (x == 0) ans = (ans + C(n + m - 1, n - 1)) % MOD;
        else {
            long long t = n + m;
            int p = 0;
            for (int i = 0; i < n; i++) {
                if ((x >> i) & 1) {
                    p++;
                    t -= a[i + 1];
                }
            }
            t -= p + 1;
            if (p & 1)
                ans = (ans - C(t, n - 1)) % MOD;
            else
                ans = (ans + C(t, n - 1)) % MOD;
        }
    }
    printf("%lld\n", (ans + MOD) % MOD);
    return 0;
}