#include <iostream>
#include <string>
#include <unordered_map>

int main() {
    std::string dna;
    int k;

    std::cin >> dna >> k;

    int len = dna.length();
    static std::unordered_map<std::string, int> hash;

    for (int i = 0; i <= len - k; i++) {
        hash[dna.substr(i, k)]++;
    }

    int ans = 0;
    for (auto each : hash) {
        ans = std::max(ans, each.second);
    }

    printf("%d\n", ans);

    return 0;
}