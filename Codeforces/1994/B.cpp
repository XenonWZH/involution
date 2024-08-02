#include <bits/stdc++.h>

namespace XenonWZH {
const int MAXN = 2e5;

void solve() {
    int n;
    scanf("%d", &n);

    static char sS[MAXN + 1], tS[MAXN + 1];
    scanf("%s", sS);
    scanf("%s", tS);

    std::vector<int> s(n + 1), t(n + 1);
    for (int i = 1; i <= n; i++) s[i] = sS[i - 1] - '0', t[i] = tS[i - 1] - '0';

    for (int i = 1; i <= n; i++) {
        if (s[i] < t[i]) {
            puts("NO");
            return;
        }
        if (s[i]) {
            puts("YES");
            return;
        }
    }

    puts("YES");
}

int main() {
    int t;

    scanf("%d", &t);

    while (t--) solve();
}
};

int main() {
    return XenonWZH::main();
}