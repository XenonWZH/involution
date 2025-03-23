#include <bits/stdc++.h>

const int MAXN = 10000;

void solve() {
    int n, k;
    static char s[MAXN + 1];

    scanf("%d %d", &n, &k);
    scanf("%s", s);

    if (k) {
        for (int i = 0; i < n; i++) {
            if (s[i] != s[0]) {
                puts("YES");
                return;
            }
        }
        puts("NO");
    } else {
        for (int i = 0; i < n / 2; i++) {
            if (s[i] < s[n - i - 1]) {
                puts("YES");
                return;
            } else if (s[i] > s[n - i - 1]) {
                puts("NO");
                return;
            }
        }
        puts("NO");
    }
}

int main() {
    int t;
    scanf("%d", &t);

    while (t--) solve();

    return 0;
}