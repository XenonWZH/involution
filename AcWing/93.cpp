// 93. 递归实现组合型枚举
// WzhDnwzWzh

#include <vector>
#include <iostream>

int n, m;
std::vector<int> chosen;

void dfs(int pos) {
    if (chosen.size() > m || chosen.size() + (n - pos + 1) < m) return;
    if (pos > n) {
        for (int each : chosen) {
            std::cout << each << " ";
        }
        std::cout << std::endl;
        return;
    }
    chosen.push_back(pos);
    dfs(pos + 1);
    chosen.pop_back();
    dfs(pos + 1);
}

int main() {
    std::cin >> n >> m;
    dfs(1);
    return 0;
}