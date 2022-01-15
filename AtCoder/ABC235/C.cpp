// C - The Kth Time Query
// XenonWZH

#include <iostream>
#include <map>
#include <vector>

int main() {
    int n, q;

    static std::map<int, std::vector<int> > ans;

    std::cin >> n >> q;

    for (int i = 1, a; i <= n; i++) {
        std::cin >> a;
        ans[a].push_back(i);
    }

    for (int i = 0, x, k; i < q; i++) {
        std::cin >> x >> k;
        if (ans[x].size() < k) std::cout << "-1" << std::endl;
        else std::cout << ans[x][k - 1] << std::endl;
    }

    return 0;
}