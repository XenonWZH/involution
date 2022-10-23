#include <cstdio>
#include <vector>
#include <algorithm>

const int MAXN = 2e5;
const int MOD = 1e9 + 7;

long long fac[MAXN + 1], inv[MAXN + 1], facInv[MAXN + 1];

inline int C(const int n, const int k) {
    if (k < 0 || k > n) return 0;
    if (k == 0) return 1;
    return fac[n] * facInv[k] % MOD * facInv[n - k] % MOD;
}

inline void prepare() {
    fac[0] = 1;
    for (int i = 1; i <= MAXN; i++) fac[i] = fac[i - 1] * i % MOD;

    inv[1] = 1;
    for (int i = 2; i <= MAXN; i++) inv[i] = ((-(MOD / i) * inv[MOD % i]) % MOD + MOD) % MOD;

    facInv[0] = 1;
    for (int i = 1; i <= MAXN; i++) facInv[i] = facInv[i - 1] * inv[i] % MOD;
}

int main() {
    prepare();

    int h, w, n;
    scanf("%d %d %d", &h, &w, &n);

    std::vector<std::pair<int, int>> a(n + 1);
    for (int i = 0; i < n; i++) scanf("%d %d", &a[i].first, &a[i].second);
    a[n].first = h, a[n].second = w;
    std::sort(a.begin(), a.end());

    std::vector<long long> f(n + 1);
    for (int i = 0; i <= n; i++) {
        f[i] = C(a[i].first + a[i].second - 2, a[i].first - 1);
        for (int j = 0; j < i; j++) {
            if (a[j].first > a[i].first || a[j].second > a[i].second) continue;
            f[i] = (f[i] - f[j] * C(a[i].first + a[i].second - a[j].first - a[j].second, a[i].first - a[j].first) % MOD + MOD) % MOD;
        }
    }

    printf("%lld\n", f[n]);

    return 0;
}