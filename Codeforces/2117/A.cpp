#include <bits/stdc++.h>

namespace XenonWZH {
typedef long long ll;

const int MAXN = 1e5;
const int MOD = 998244353;

void solve() {
    int n, x;
    scanf("%d %d", &n, &x);

    std::vector<int> a(n + 1);
    for (int i = 1; i <= n; i++) scanf("%d", &a[i]);

    bool can = true;
    int y = -1;
    for (int i = 1; i <= n; i++) {
        if (a[i]) {
            y = i;
            break;
        }
    }

    if (x == -1) {
        puts("YES");
        return;
    }

    for (int i = y + x; i <= n; i++) {
        if (a[i]) {
            puts("NO");
            return;
        }
    }

    puts("YES");
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    int t;
    scanf("%d", &t);

    while (t--) solve();

    return 0;
}
};

int main() { return XenonWZH::main(); }