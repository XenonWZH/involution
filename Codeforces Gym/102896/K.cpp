#include <algorithm>
#include <bits/stdc++.h>

namespace XenonWZH {
int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    int n;
    std::cin >> n;

    std::vector<std::pair<int, int>> ans;
    for (int i = 1; i <= n; i++) {
        int p;
        std::string s;
        std::cin >> p >> s;

        std::vector<int> cnt(10, 0);
        for (char c : s) cnt[c - '0']++;

        if (cnt[2] >= 2 && cnt[1] && cnt[0]) ans.push_back(std::make_pair(p, i));
    }

    if (ans.size()) {
        std::sort(ans.begin(), ans.end());
        std::cout << ans[0].second << "\n";
    } else std::cout << "0\n";

    return 0;
}
}

int main() {
    return XenonWZH::main();
}