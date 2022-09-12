#include <cstdio>
#include <cstring>
#include <cmath>
#include <iostream>
#include <algorithm>

const int MAXN = 2e5;

int main() {
    int t;

    scanf("%d", &t);

    while (t--) {
        static char s[MAXN + 2];
        scanf("%s", s + 1);

        int n = strlen(s + 1);
        static std::pair<int, int> a[MAXN + 1];
        for (int i = 1; i <= n; i++) a[i] = std::make_pair(s[i] - 'a' + 1, i);
        std::sort(a + 1, a + n + 1);

        int begin = 0, end = 0;
        for (int i = 1; i <= n; i++) {
            if (a[i].second == 1) begin = i;
            if (a[i].second == n) end = i;
        }
        int l = begin, r = end;
        if (l > r) std::swap(l, r);
        while (l > 1 && a[l].first == a[l - 1].first) std::swap(a[l], a[l - 1]), l--;
        while (r < n && a[r].first == a[r + 1].first) std::swap(a[r], a[r + 1]), r++;

        int cost = 0;
        for (int i = l + 1; i <= r; i++) cost += std::abs(a[i].first - a[i - 1].first);

        printf("%d %d\n", cost, r - l + 1);
        if (begin == l) for (int i = l; i <= r; i++) printf("%d ", a[i].second);
        else for (int i = r; i >= l; i--) printf("%d ", a[i].second);
        putchar('\n');
    }

    return 0;
}