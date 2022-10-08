#include <bits/stdc++.h>

const int MAXN = 200;

void solve() {
    int n, k;
    static char s[MAXN + 1];

    scanf("%d %d", &n, &k);
    scanf("%s", s);

    std::vector<int> cnt(26, 0);
    for (int i = 0; i < n; i++) cnt[s[i] - 'a']++;

    std::vector<char> ans(k, 'a');
    int max = k, cost = 0;
    for (int i = 0; i < std::min(26, n / k); i++) {
        max = std::min(max, cnt[i]);
        for (int i = 0; i < max; i++) ans[i]++;
    }

    for (int i = 0; i < k; i++) putchar(ans[i]);
    putchar('\n');
}

int main() {
    int t;

    scanf("%d", &t);

    while (t--) solve();

    return 0;
}