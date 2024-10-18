#include <bits/stdc++.h>

int main() {
    int n;
    scanf("%d", &n);

    std::vector<int> a(n + 1), b(n + 1);
    for (int i = 1; i <= n; i++) scanf("%d", &a[i]), b[a[i]] = i;

    int ans = 0;
    for (int i = 1; i <= n; i++) {
        if (a[i] == i) continue;
        ans++;
        int t = b[i];
        std::swap(a[i], a[t]);
        b[a[i]] = i, b[a[t]] = t;
    }

    printf("%d\n", ans);

    return 0;
}