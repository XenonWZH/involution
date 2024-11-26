#include <cstdio>
#include <vector>
#include <algorithm>

int main() {
    int n;
    scanf("%d", &n);

    std::vector<int> a(n + 1);
    for (int i = 1; i <= n; i++) scanf("%d", &a[i]);

    std::vector<int> b(n / 2 + 1);
    for (int i = 1; i <= n / 2; i++) b[i] = a[i] - a[n - i + 1];

    long long ans = 0, res = 0;
    for (int i = 1; i <= n / 2; i++) {
        if (res * b[i] <= 0) ans += std::abs(b[i]), res = b[i];
        else if (std::abs(res) >= std::abs(b[i])) res = 0;
        else ans += std::abs(res - b[i]), res = b[i] - res;
    }

    printf("%lld\n", ans);

    return 0;
}