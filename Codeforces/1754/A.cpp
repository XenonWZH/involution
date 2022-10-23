#include <bits/stdc++.h>

void solve() {
    int n;
    scanf("%d", &n);

    std::string s;
    std::cin >> s;

    if (s[0] == 'A') {
        puts("No");
        return;
    }

    int cntq = 0, cnta = 0;
    for (int i = 0; i < n; i++) {
        if (s[i] == 'Q') cntq++;
        else cntq--;
        cntq = std::max(cntq, 0);
    }

    if (cntq > 0) puts("No");
    else puts("Yes");
}

int main() {
    int t;

    scanf("%d", &t);

    while (t--) solve();

    return 0;
}