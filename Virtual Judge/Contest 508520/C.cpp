#include <cstdio>
#include <algorithm>

const int MAXN = 1e7;
const int MOD = 100000001;

int main() {
    int n, A, B, C;
    static int a[MAXN + 1];

    scanf("%d %d %d %d %d", &n, &A, &B, &C, &a[1]);
    for (int i = 2; i <= n; i++) a[i] = ((long long)a[i - 1] * A + B) % MOD;
    for (int i = 1; i <= n; i++) a[i] = a[i] % C + 1;

    double ans = 1.0 / std::max(a[1], a[n]);
    for (int i = 2; i <= n; i++) {
        ans += 1.0 / std::max(a[i], a[i - 1]);
    }

    printf("%.3f\n", ans);

    return 0;
}