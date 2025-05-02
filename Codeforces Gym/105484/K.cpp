#include <bits/stdc++.h>

namespace XenonWZH {
void solve() {
    int n, m, k, w;
    scanf("%d %d %d %d", &n, &m, &k, &w);

    std::vector<int> a(n + 1), b(m + 3);
    for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
    for (int i = 2; i <= m + 1; i++) scanf("%d", &b[i]);
    b[1] = 0, b[m + 2] = w + 1, m += 2;

    std::sort(a.begin() + 1, a.end());
    std::sort(b.begin() + 1, b.end());

    std::vector<int> ans;
    int p = 1;
    for (int i = 1; i <= m - 1; i++) {
        std::vector<int> c;
        while (p <= n && a[p] < b[i + 1]) c.push_back(a[p++]);

        int sz = c.size(), back = b[i];
        std::vector<int> anss;
        for (int j = 0; j < sz; j++) {
            if (back < c[j]) {
                anss.push_back(c[j]);
                back = c[j] + k - 1;
            }
        }

        if (!anss.empty()) {
            back = b[i + 1];
            int szz = anss.size();
            for (int j = szz - 1; j >= 0; j--) {
                if (anss[j] + k - 1 >= back) anss[j] = back - k;
                back = anss[j];
            }
            if (anss[0] <= b[i]) {
                puts("-1");
                return;
            }

            for (auto x : anss) ans.push_back(x);
        }
    }

    printf("%zu\n", ans.size());
    for (auto x : ans) printf("%d ", x);
    puts("");
}

int main() {
    int t;
    scanf("%d", &t);

    while (t--) solve();

    return 0;
}
};

int main() { return XenonWZH::main(); }