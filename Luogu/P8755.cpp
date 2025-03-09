#include <bits/stdc++.h>

int main() {
    int n, m;
    scanf("%d %d", &n, &m);

    std::vector<int> v(n + 1);
    for (int i = 1; i <= n; i++) scanf("%d", &v[i]);

    std::vector<int> res(n + 1);
    for (int i = 1; i <= n; i++) res[i] = v[i];

    std::priority_queue<std::tuple<int, int, int>, std::vector<std::tuple<int, int, int>>, std::greater<std::tuple<int, int, int>>> task;

    while (m--) {
        int a, b, c, d;
        scanf("%d %d %d %d", &a, &b, &c, &d);

        while ((!task.empty()) && (std::get<0>(task.top()) <= a)) {
            res[std::get<1>(task.top())] += std::get<2>(task.top());
            task.pop();
        }

        if (res[b] >= d) {
            res[b] -= d;
            task.push(std::make_tuple(a + c, b, d));
            printf("%d\n", res[b]);
        } else puts("-1");
    }

    return 0;
}