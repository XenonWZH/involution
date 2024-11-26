#include <cstdio>
#include <vector>
#include <algorithm>

int main() {
    int n, m;
    scanf("%d %d", &n, &m);

    std::vector<int> a(n);
    for (int i = 0; i < n; i++) scanf("%d", &a[i]);
    std::sort(a.begin(), a.end());

    int ans = 0;
    for (int i = 0; i <= m; i++) {
        int r = i, l = m - i;
        int lv = std::min(0, r - l), rv = r;
        ans = std::max(ans, (int)(std::upper_bound(a.begin(), a.end(), rv) - std::lower_bound(a.begin(), a.end(), lv)));
    }
    for (int i = 0; i <= m; i++) {
        int l = i, r = m - i;
        int lv = -l, rv = std::max(0, r - l);
        ans = std::max(ans, (int)(std::upper_bound(a.begin(), a.end(), rv) - std::lower_bound(a.begin(), a.end(), lv)));
    }

    printf("%d\n", ans);

    return 0;
}