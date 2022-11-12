#include <cstdio>
#include <vector>
#include <map>
#include <algorithm>

int main() {
    int n, q;
    scanf("%d %d", &n, &q);

    std::vector<int> a(n + 1);
    for (int i = 1; i <= n; i++) scanf("%d", &a[i]);

    std::vector<int> res(n + 1);
    for (int i = 1; i <= n; i++) res[i] = res[i - 1] ^ a[i];

    std::vector<int> cnt0(n + 1);
    for (int i = 1; i <= n; i++) cnt0[i] = cnt0[i - 1] + (a[i] == 0);

    std::map<int, std::vector<int>> f[2];
    for (int i = 1; i <= n; i++) f[i % 2][res[i]].push_back(i);

    while (q--) {
        int l, r;
        scanf("%d %d", &l, &r);

        if (cnt0[r] - cnt0[l - 1] == r - l + 1) puts("0");
        else if (res[l - 1] != res[r]) puts("-1");
        else if ((r - l + 1) % 2 || a[l] == 0 || a[r] == 0) puts("1");
        else {
            auto p = std::lower_bound(f[l % 2][res[l - 1]].begin(), f[l % 2][res[l - 1]].end(), l);
            if (p != f[l % 2][res[l - 1]].end() && *p < r) puts("2");
            else puts("-1");
        }
    }

    return 0;
}