#include <cstdio>
#include <climits>
#include <algorithm>
#include <queue>

int phi(int n) {
    if (n == 1) return 1;
    for (int i = 2; i * i <= n; i++) {
        if (n % i == 0) {
            if ((n / i) % i == 0) return phi(n / i) * i;
            else return phi(n / i) * (i - 1);
        }
    }
    return n - 1;
}

int solve(int n, int k) {
    if (n == 1) return 0;

    std::queue<std::pair<std::pair<int, int>, int>> q;
    q.emplace(std::make_pair(n, k), 0);

    while (!q.empty()) {
        auto u = q.front();
        q.pop();

        if (u.first.first == 1) return u.second;
        if (u.first.second) q.emplace(std::make_pair(u.first.first / 2 + 1, u.first.second - 1), u.second + 1);
        q.emplace(std::make_pair(phi(u.first.first), u.first.second), u.second + 1);
    }

    return INT_MAX;
}

int main() {
    freopen("func.in", "r", stdin);
    freopen("func.out", "w", stdout);

    int t;
    scanf("%d", &t);

    while (t--) {
        int n, k;
        scanf("%d %d", &n, &k);

        printf("%d\n", solve(n, k));
    }

    fclose(stdin);
    fclose(stdout);

    return 0;
}