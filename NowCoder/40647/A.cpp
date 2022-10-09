#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>

const int MAXN = 5000;
const long long INF = 0x3f3f3f3f3f3f3f3f;

int main() {
    int n, m;
    static long long a[MAXN + 1];

    scanf("%d %d", &n, &m);
    for (int i = 1; i < n + 1; i++) scanf("%lld", &a[i]);

    std::sort(a + 1, a + n + 1);
    static long long diff[MAXN + 1];
    for (int i = 1; i < n; i++) diff[i] = a[i + 1] - a[i];

    static long long f[MAXN + 1][2];
    memset(f, 0x3f, sizeof(f));
    f[0][0] = f[0][1] = 0;
    for (int i = 1; i < n; i++) {
        for (int j = m; j >= 0; j--) {
            f[j][0] = std::min(f[j][0], f[j][1]);
            f[j][1] = std::min(INF, (j > 0 ? f[j - 1][0] : INF) + diff[i]);
        }
    }

    printf("%lld\n", std::min(f[m][0], f[m][1]));

    return 0;
}