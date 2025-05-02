#include <bits/stdc++.h>

namespace XenonWZH {
void solve() {
    std::string s;
    std::cin >> s;
    int n = s.length();
    s = ' ' + s;

    int cnt[3] = { 0, 0, 0 };
    for (int i = 1; i <= n; i++) cnt[s[i] - '0'] += (s[i] == '2' ? 1 : (i % 2 == 0 ? 1 : -1));

    cnt[0] = std::abs(cnt[0]), cnt[1] = std::abs(cnt[1]);

    int t = std::min(cnt[0], cnt[2]);
    cnt[2] -= t, cnt[0] -= t;
    t = std::min(cnt[1], cnt[2]);
    cnt[2] -= t, cnt[1] -= t;

    printf("%d\n", cnt[2] % 2 + cnt[0] + cnt[1]);
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    int t;
    std::cin >> t;

    while (t--) solve();

    return 0;
}
};

int main() { return XenonWZH::main(); }