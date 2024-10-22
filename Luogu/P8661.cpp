#include <bits/stdc++.h>

const int MAXN = 1e5;

int main() {
    int n, d, k;
    scanf("%d %d %d", &n, &d, &k);

    std::vector<std::queue<int>> bbs(MAXN + 1);
    std::vector<std::pair<int, int>> q(n + 1);
    for (int i = 1; i <= n; i++) scanf("%d %d", &q[i].first, &q[i].second);
    std::sort(q.begin() + 1, q.end());

    std::vector<bool> hot(MAXN + 1, false);
    for (int i = 1; i <= n; i++) {
        bbs[q[i].second].push(q[i].first);
        while (!bbs[q[i].second].empty() && q[i].first - bbs[q[i].second].front() >= d) bbs[q[i].second].pop();
        if (bbs[q[i].second].size() >= k) hot[q[i].second] = true;
    }

    for (int i = 0; i <= MAXN; i++) if (hot[i]) printf("%d\n", i);

    return 0;
}