#include <bits/stdc++.h>

namespace XenonWZH {
typedef long long ll;

const int MAXN = 1e5;
const int MOD = 998244353;

void solve() {
    int n;
    scanf("%d", &n);

    std::vector<int> d(n + 1);
    for (int i = 1; i <= n; i++) scanf("%d", &d[i]);

    std::vector<int> l(n + 1), r(n + 1);
    for (int i = 1; i <= n; i++) scanf("%d %d", &l[i], &r[i]);

    std::vector<int> ans;
    int ll = 0, rr = 0, cc = 0;
    for (int i = 1; i <= n; i++) {
        if (d[i] != -1) ll += d[i], rr += d[i];
        else rr++, cc++;

        if (ll > r[i] || rr < l[i]) {
            puts("-1");
            return;
        }

        for (int j = ll; j < l[i]; j++) ans.push_back(1);
        ll = std::max(ll, l[i]);
        for (int j = rr; j > r[i]; j--) ans.push_back(0);
        rr = std::min(rr, r[i]);

        if (ans.size() > cc) {
            puts("-1");
            return;
        }
    }
    
    ans.resize(n + 1, 0);

    int cnt = 0;
    for (int i = 1; i <= n; i++) printf("%d ", d[i] == -1 ? ans[cnt++] : d[i]);
    puts("");
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