#include <cstdio>
#include <algorithm>

const int MAXN = 1e5;
const int MOD = 1e8 - 3;

int n;
std::pair<unsigned long long, int> a[MAXN + 1], b[MAXN + 1];
int c[MAXN + 1];

void add(int x, int y) {
    for (; x <= n; x += x & -x) c[x] += y;
}

int ask(int x) {
    int ans = 0;
    for (; x; x -= x & -x) ans += c[x];
    return ans;
}

int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) scanf("%llu", &a[i].first), a[i].second = i;
    for (int i = 1; i <= n; i++) scanf("%llu", &b[i].first), b[i].second = i;

    std::sort(a + 1, a + n + 1);
    std::sort(b + 1, b + n + 1);

    static int x[MAXN + 1];
    for (int i = 1; i <= n; i++) x[b[i].second] = a[i].second;

    unsigned long long ans = 0;
    for (int i = n; i; i--) {
        ans = (ans + ask(x[i] - 1)) % MOD;
        add(x[i], 1);
    }

    printf("%llu\n", ans);

    return 0;
}