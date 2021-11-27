// Q2.1.4.3. 跳箱子
// WzhDnwzWzh

#include <cstring>
#include <iostream>
#include <map>

int n, m;

int vis[10] = { 0 };

std::map<int, std::string> en;

void solve(int pos, int start) {
    if (pos >= m) return;

    for (int i = start; i <= n + pos - m + 1; i++) {
        if (vis[pos] != i) {
            std::cout << (en[pos] + "->") << i << " ";
            vis[pos] = i;
        }
        if (pos == m - 1) std::cout << std::endl;
        solve(pos + 1, i + 1);
    }
}

int main() {
    std::cin >> n >> m;

    for (int i = 0; i < 26; i++) {
        en[i] = char('A' + i);
    }

    solve(0, 1);

    return 0;
}