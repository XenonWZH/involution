#include <bits/stdc++.h>

namespace XenonWZH {
typedef long long ll;

void solve() {
    std::vector<std::pair<int, std::string>> a(4), b(4);
    for (int i = 0; i < 4; i++) std::cin >> a[i].second >> a[i].first;
    for (int i = 0; i < 4; i++) std::cin >> b[i].second >> b[i].first;

    std::sort(a.begin(), a.end());
    std::sort(b.begin(), b.end());

    std::cout << std::max(a[3], b[3]).second << " beats " << std::min(a[3], b[3]).second << "\n";
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    int t = 1;

    while (t--) solve();

    return 0;
}
};

int main() { return XenonWZH::main(); }