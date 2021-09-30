// 94. 递归实现排列型枚举
// WzhDnwzWzh

#include <cstring>
#include <iostream>

int order[11], n;
bool chosen[11];

void dfs(int pos) {
    if (pos > n) {
        for (int i = 1; i <= n; i++)
            std::cout << order[i] << " ";
        std::cout << std::endl;
        return;
    }
    for (int i = 1; i <= n; i++) {
        if (!chosen[i]) {
            chosen[i] = true;
            order[pos] = i;
            dfs(pos + 1);
            chosen[i] = false;
        }
    }
}

int main() {
    memset(chosen, false, sizeof(chosen));
    std::cin >> n;
    dfs(1);
    return 0;
}