#include <climits>
#include <iostream>
#include <string>
#include <vector>
#include <array>
#include <algorithm>

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    std::string s, t;
    std::cin >> s >> t;
    int n = s.size(), m = t.size();
    s = ' ' + s, t = ' ' + t + ' ';

    std::vector<int> next(m + 1);
    next[1] = 0;
    for (int i = 2, j = 0; i <= m; i++) {
        while (j && t[j + 1] != t[i]) j = next[j];
        if (t[j + 1] == t[i]) j++;
        next[i] = j;
    }

    std::vector<std::array<int, 'z' + 1>> jump(m + 1);
    jump[0][t[1]] = 1;
    for (int i = 1; i <= m; i++) {
        for (int j = 'a'; j <= 'z'; j++) {
            if (i < m && j == t[i + 1]) jump[i][j] = i + 1;
            else jump[i][j] = jump[next[i]][j];
        }
    }

    std::vector<std::vector<int>> f(n + 1, std::vector<int>(m + 1, INT_MIN));
    f[0][0] = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j <= m; j++) {
            if (f[i][j] != INT_MIN) {
                if (s[i + 1] == '?') {
                    for (int c = 'a'; c <= 'z'; c++) {
                        f[i + 1][jump[j][c]] = std::max(f[i + 1][jump[j][c]], f[i][j] + (jump[j][c] == m));
                    }
                } else f[i + 1][jump[j][s[i + 1]]] = std::max(f[i + 1][jump[j][s[i + 1]]], f[i][j] + (jump[j][s[i + 1]] == m));
            }
        }
    }

    std::cout << *std::max_element(f[n].begin(), f[n].end()) << std::endl;

    return 0;
}