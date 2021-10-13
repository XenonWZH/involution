// P1090 [NOIP2004 提高组] 合并果子 / [USACO06NOV] Fence Repair G
// WzhDnwzWzh

#include <iostream>
#include <queue>

int main() {
    int n;

    std::cin >> n;
    std::priority_queue<int, std::vector<int>, std::greater<int> > apple;
    for (int i = 0, x; i < n; i++) {
        std::cin >> x;
        apple.push(x);
    }

    int ans = 0;
    while (apple.size() >= 2) {
        int a = 0;
        a += apple.top();
        apple.pop();
        a += apple.top();
        apple.pop();
        apple.push(a);
        ans += a;
    }

    std::cout << ans << std::endl;
    return 0;
}