#include <iostream>
#include <vector>

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    std::cout.tie(0);

    std::string s;
    std::cin >> s;

    int n = s.length();
    s = ' ' + s;

    std::vector<int> next(n + 1);
    next[0] = next[1] = 0;
    for (int i = 2, j = 0; i <= n; i++) {
        while (j && s[i] != s[j + 1]) j = next[j];
        if (s[i] == s[j + 1]) j++;
        next[i] = j;
    }

    std::vector<int> f(n + 1), g(n + 1);
    f[1] = g[1] = 1;
    for (int i = 2; i <= n; i++) {
        if (g[f[next[i]]] >= i - next[i]) f[i] = f[next[i]];
        else f[i] = i;
        g[f[i]] = i;
    }

    printf("%d\n", f[n]);

    return 0;
}