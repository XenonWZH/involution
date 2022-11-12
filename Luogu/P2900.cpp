#include <cstdio>
#include <vector>
#include <algorithm>
#include <functional>

int main() {
    int n;
    scanf("%d", &n);

    std::vector<std::pair<long long, long long>> a(n + 1);
    for (int i = 1; i <= n; i++) scanf("%lld %lld", &a[i].first, &a[i].second);

    std::sort(a.begin() + 1, a.end(), std::greater<std::pair<long long, long long>>());
    int m = 0;
    for (int i = 1; i <= n; i++) if (a[i].second > a[m].second) a[++m] = a[i];
    n = m;

    std::vector<long long> f(n + 1);
    std::vector<int> q(n + 1);
    int l = 1, r = 1;
    q[1] = 0;
    auto slope = [&](int i, int j) { return 1.0 * (f[i] - f[j]) / (a[j + 1].first - a[i + 1].first); };

    for (int i = 1; i <= n; i++) {
        while (l < r && slope(q[l], q[l + 1]) <= a[i].second) l++;
        f[i] = f[q[l]] + 1ll * a[q[l] + 1].first * a[i].second;
        while (l < r && slope(q[r - 1], q[r]) >= slope(q[r], i)) r--;
        q[++r] = i;
    }

    printf("%lld\n", f[n]);

    return 0;
}