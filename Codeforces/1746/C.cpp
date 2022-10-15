#include <cstdio>
#include <vector>
#include <algorithm>

void solve() {
    int n;
    scanf("%d", &n);

    std::vector<std::pair<int, int>> a(n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i].first);
        a[i].second = i + 1;
    }

    std::sort(a.begin(), a.end());

    for (int i = n - 1; i >= 0; i--) printf("%d ", a[i].second);
    putchar('\n');
}

int main() {
    int t;

    scanf("%d", &t);

    while (t--) solve();

    return 0;
}