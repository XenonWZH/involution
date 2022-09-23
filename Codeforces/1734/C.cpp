#include <cstdio>
#include <cstring>
#include <iostream>
#include <vector>

const int MAXN = 1e6;

inline void solve() {
    int n;
    static char s[MAXN + 1];

    scanf("%d", &n);
    scanf("%s", s + 1);

    static std::vector<int> a;
    a.clear();
    for (int i = 1; i <= n; i++) {
        if (s[i] == '0') {
            a.push_back(i);
        }
    }

    long long ans = 0;
    static bool v[MAXN + 1];
    memset(v, false, sizeof(v));
    for (int i : a) {
        for (int j = i; j <= n; j += i) {
            if (s[j] != '0') break;
            if (!v[j]) {
                v[j] = true;
                ans += i;
            }
        }
    }

    printf("%lld\n", ans);
}

int main() {
    int t;

    scanf("%d", &t);

    while (t--) solve();

    return 0;
}