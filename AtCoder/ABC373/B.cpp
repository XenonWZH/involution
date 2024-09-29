#include <bits/stdc++.h>

int main() {
    std::string s;
    std::cin >> s;
    int p[26];
    for (int i = 0; i < 26; i++) p[s[i] - 'A'] = i;
    long long ans = 0;
    for (int i = 1; i < 26; i++) ans += std::abs(p[i] - p[i - 1]);
    std::cout << ans << "\n";
    return 0;
}