#include <cstdio>
#include <vector>
#include <algorithm>

void solve() {
    int n, m;
    scanf("%d %d", &n, &m);

    using Person = std::tuple<int, int, int>;
    std::vector<Person> a(n);
    for (int i = 0; i < n; i++) scanf("%d %d %d", &std::get<0>(a[i]), &std::get<1>(a[i]), &std::get<2>(a[i]));
    std::sort(a.begin(), a.end());

    int l = m - std::get<0>(a[0]), r = m + std::get<0>(a[0]);
    for (int i = 0; i < n; i++) {
        l = std::max(l, std::get<1>(a[i]));
        r = std::min(r, std::get<2>(a[i]));
        if (l > r) {
            puts("NO");
            return;
        }

        if (i != n - 1) {
            l -= std::get<0>(a[i + 1]) - std::get<0>(a[i]);
            r += std::get<0>(a[i + 1]) - std::get<0>(a[i]);
        }
    }

    puts("YES");
}

int main() {
    int t;
    scanf("%d", &t);

    while (t--) solve();

    return 0;
}