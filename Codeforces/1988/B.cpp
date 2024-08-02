#include <bits/stdc++.h>

namespace XenonWZH {
const int MAXN = 2e5;

void solve() {
    int n;
    static char s[MAXN + 10];

    scanf("%d", &n);
    scanf("%s", s);

    if (n == 1) {
        if (s[0] == '1') {
            puts("Yes");
            return;
        } else {
            puts("No");
            return;
        }
    }

    int cnt[2] = { 0, 0 };
    cnt[s[0] - '0']++;
    for (int i = 1; i < n; i++) {
        if (s[i] == '1') cnt[1]++;
        else if (s[i - 1] == '1') cnt[0]++;
    }

    puts(cnt[0] >= cnt[1] ? "No" : "Yes");
}

int main() {
    int t;

    scanf("%d", &t);

    while (t--) solve();

    return 0;
}
};

int main() {
    return XenonWZH::main();
}