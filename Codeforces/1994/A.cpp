#include <bits/stdc++.h>

namespace XenonWZH {
void solve() {
    int n, m;
    scanf("%d %d", &n, &m);

    std::vector<std::vector<int>> a(n + 1, std::vector<int>(m + 1));
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            scanf("%d", &a[i][j]);
        }
    }

    if (n == 1 && m == 1) {
        puts("-1");
        return;
    }

    if (m == 1) {
        for (int i = 2; i <= n; i++) printf("%d\n", a[i][1]);
        printf("%d\n", a[1][1]);
        return;
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 2; j <= m; j++) printf("%d ", a[i][j]);
        printf("%d\n", a[i][1]);
    }
}

int main() {
    int t;

    scanf("%d", &t);

    while (t--) solve();
}
};

int main() {
    return XenonWZH::main();
}