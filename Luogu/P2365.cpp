#include <cstdio>
#include <climits>
#include <vector>
#include <algorithm>

int main() {
    int n, s;
    scanf("%d %d", &n, &s);

    std::vector<int> t(n + 1), c(n + 1);
    for (int i = 1; i <= n; i++) scanf("%d %d", &t[i], &c[i]);
    std::vector<long long> st(n + 1), sc(n + 1);
    for (int i = 1; i <= n; i++) st[i] = st[i - 1] + t[i], sc[i] = sc[i - 1] + c[i];

    std::vector<long long> f(n + 1, LLONG_MAX);
    f[0] = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j < i; j++) {
            f[i] = std::min(f[i], f[j] + st[i] * (sc[i] - sc[j]) + s * (sc[n] - sc[j]));
        }
    }

    printf("%lld\n", f[n]);

    return 0;
}
