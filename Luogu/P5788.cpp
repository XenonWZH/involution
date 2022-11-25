#include <cstdio>
#include <vector>
#include <stack>

int main() {
    int n;
    scanf("%d", &n);

    std::vector<int> a(n + 1);
    for (int i = 1; i <= n; i++) scanf("%d", &a[i]);

    std::stack<int> s;
    std::vector<int> ans(n + 1);
    for (int i = n; i >= 1; i--) {
        while (!s.empty() && a[s.top()] <= a[i]) s.pop();
        ans[i] = s.empty() ? 0 : s.top();
        s.push(i);
    }

    for (int i = 1; i <= n; i++) printf("%d ", ans[i]);
    putchar('\n');

    return 0;
}