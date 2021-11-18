// #537. 「LibreOJ NOIP Round #1」DNA 序列
// WzhDnwzWzh

#include <iostream>
#include <unordered_map>

int main() {
    static std::string dna;
    int k;

    std::cin >> dna >> k;

    static std::unordered_map<std::string, int> cnt;
    for (int i = 0, len = dna.size(); i <= len - k; i++) ++cnt[dna.substr(i, k)];

    int ans = 0;
    for (auto each : cnt) if (each.second > ans) ans = each.second;

    std::cout << ans << std::endl;

    return 0;
}
