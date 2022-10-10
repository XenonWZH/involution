#include <bits/stdc++.h>

void solve() {
    int n;
    scanf("%d", &n);

    std::vector<int> a(n), b(n);
    for (int i = 0; i < n; i++) scanf("%d", &a[i]);
    for (int i = 0; i < n; i++) scanf("%d", &b[i]);

    int ans1 = 0;
    for (int i = 0; i < n; i++) if (a[i] != b[i]) ans1++;

    int cntA = 0, cntB = 0;
    for (int i = 0; i < n; i++) {
        if (a[i] == 0) cntA++;
        if (b[i] == 0) cntB++;
    }
    int ans2 = std::abs(cntA - cntB) + 1;

    printf("%d\n", std::min(ans1, ans2));
}

int main() {
    int t;

    scanf("%d", &t);

    while (t--) solve();

    return 0;
}