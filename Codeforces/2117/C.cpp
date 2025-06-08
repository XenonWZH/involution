#include <bits/stdc++.h>

namespace XenonWZH {
typedef long long ll;

const int MAXN = 1e5;
const int MOD = 998244353;

void solve() {
    int n;
    scanf("%d", &n);

    std::vector<int> a(n + 1);
    for (int i = 1; i <= n; i++) scanf("%d", &a[i]);

    std::vector<int> pos(n + 1, 0), aft(n + 1);
    for (int i = 1; i <= n; i++) {
        aft[pos[a[i]]] = i;
        pos[a[i]] = i;
    }

    int ans = 1, now = 1, end = 1;
    for (int i = 1; i <= n; i++) {
        if (i > now) {
            ans++;
            now = end;
        }
        if (aft[i] == 0) break;
        end = std::max(end, aft[i]);
    }

    printf("%d\n", ans);
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