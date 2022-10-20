#include <bits/stdc++.h>

void solve() {
    int n, m;
    scanf("%d %d", &n, &m);

    std::vector<int> row(n), col(n);
    for (int i = 0; i < m; i++) {
        int r, c;
        scanf("%d %d", &r, &c);
        row[r - 1]++, col[c - 1]++;
    }

    int cnt = 0;
    for (int i = 0; i < n; i++) if (row[i] > 1) cnt++;
    if (cnt > 1) puts("NO");

    cnt = 0;
    for (int i = 0; i < n; i++) if (col[i] > 1) cnt++;
    if (cnt > 1) puts("NO");

    puts(m == n ? "NO" : "YES");
}

int main() {
    int t;

    scanf("%d", &t);

    while (t--) solve();

    return 0;
}