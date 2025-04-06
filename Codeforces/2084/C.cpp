#include <bits/stdc++.h>

namespace XenonWZH {
typedef long long ll;

const int MAXN = 1e5;
const int MOD = 998244353;

void solve() {
    int n;
    scanf("%d", &n);

    std::vector<int> a(n + 1), b(n + 1);
    for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
    for (int i = 1; i <= n; i++) scanf("%d", &b[i]);

    int cnt = 0, pos = 0;
    for (int i = 1; i <= n; i++) if (a[i] == b[i]) cnt++, pos = a[i];
    if ((n % 2 == 0 && cnt != 0) || (n % 2 == 1 && cnt != 1)) {
        puts("-1");
        return;
    }

    std::map<int, int> check;
    for (int i = 1; i <= n; i++) {
        if (check[std::min(a[i], b[i])] && check[std::min(a[i], b[i])] != std::max(a[i], b[i])) {
            puts("-1");
            return;
        }
        check[std::min(a[i], b[i])] = std::max(a[i], b[i]);
    }

    for (int i = 1; i <= n; i++) a[i] = std::min(a[i], b[i]);

    std::vector<int> c(n + 1);
    std::map<int, int> poss;
    cnt = 0;
    if (n % 2 == 1) {
        for (int i = 1; i <= n; i++) {
            if (!poss[a[i]]) {
                if (a[i] == pos) c[i] = (n + 1) / 2;
                else {
                    if (cnt + 1 == (n + 1) / 2) cnt += 2;
                    else cnt++;
                    c[i] = poss[a[i]] = cnt;
                }
            } else c[i] = n + 1 - poss[a[i]];
        }
    } else {
        for (int i = 1; i <= n; i++) {
            if (!poss[a[i]]) c[i] = poss[a[i]] = ++cnt;
            else c[i] = n + 1 - poss[a[i]];
        }
    }

    std::vector<int> d(n + 1);
    for (int i = 1; i <= n; i++) d[c[i]] = i;

    std::vector<std::pair<int, int>> ans;
    for (int i = 1; i <= n; i++) {
        if (c[i] != i) {
            ans.emplace_back(i, d[i]);
            int pp = d[i];
            d[i] = i;
            d[c[i]] = pp;
            std::swap(c[i], c[pp]);
        }
    }

    printf("%zu\n", ans.size());
    for (auto [u, v] : ans) printf("%d %d\n", u, v);
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