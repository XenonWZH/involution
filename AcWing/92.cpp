// 92. 递归实现指数型枚举
// WzhDnwzWzh

#include <vector>
#include <iostream>

int n;
std::vector<int> chosen;

void dfs(int pos) {
    if (pos > n) {
        for (int each : chosen) {
            std::cout << each << " ";
        }
        std::cout << std::endl;
        return;
    }
    dfs(pos + 1);
    chosen.push_back(pos);
    dfs(pos + 1);
    chosen.pop_back();
}

int main() {
    std::cin >> n;
    dfs(1);
    return 0;
}