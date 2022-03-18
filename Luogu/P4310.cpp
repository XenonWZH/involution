#include <cstdio>
#include <cstring>
#include <iostream>

const int MAXN = 1e5;

int main() {
    int n;
    static int a[MAXN + 1];

    std::cin >> n;

    for (int i = 1; i <= n; i++) {
        scanf("%d", &a[i]);
    }

    static int f[MAXN + 1], bit[31], ans = 0;
    memset(bit, 0, sizeof(bit));

    for (int i = 1; i <= n; i++) {
        f[i] = 1;

        for (int j = 0; (1ll << j) <= a[i]; j++) {
            if (((1 << j) & a[i]) != 0) {
                f[i] = std::max(f[i], bit[j] + 1);
            }
        }
        ans = std::max(ans, f[i]);
        for (int j = 0; (1ll << j) <= a[i]; j++) {
            if (((1 << j) & a[i]) != 0) {
                bit[j] = std::max(bit[j], f[i]);
            }
        }
    }

    std::cout << ans << std::endl;

    return 0;
}