#include <iostream>
#include <vector>

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    int n;
    std::string s;
    std::cin >> n >> s;
    s = ' ' + s;

    std::vector<int> next(n + 1);
    next[1] = 0;
    for (int i = 2, j = 0; i <= n; i++) {
        while (j && s[i] != s[j + 1]) j = next[j];
        if (s[i] == s[j + 1]) j++;
        next[i] = j;
    }

    long long ans = 0;
    for (int i = 1; i <= n; i++) {
        int j = i;
        while (next[j]) j = next[j];
        if (next[i] != 0) next[i] = j;
        ans += i - j;
    }

    printf("%lld\n", ans);

    return 0;
}