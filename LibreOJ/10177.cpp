#include <cstdio>
#include <cstring>
#include <iostream>
#include <queue>

const int MAXN = 100000;

int n, k;
long long e[MAXN + 1];
long long f[MAXN + 1][2], sum[MAXN + 1];

long long dp() {
    memset(f, 0, sizeof(f));
    f[1][1] = e[1];
    std::deque<int> q;
    q.push_back(0);
    q.push_back(1);

    for (int i = 2; i <= n; i++) {
        f[i][0] = std::max(f[i - 1][0], f[i - 1][1]);
        while (!q.empty() && q.front() < i - k) q.pop_front();
        f[i][1] = f[q.front()][0] + sum[i] - sum[q.front()];
        while (!q.empty() && f[i][0] - sum[i] > f[q.back()][0] - sum[q.back()]) q.pop_back();
        q.push_back(i);
    }

    return std::max(f[n][1], f[n][0]);
}

int main() {
    std::cin >> n >> k;

    sum[0] = 0;
    for (int i = 1; i <= n; i++) {
        scanf("%lld", &e[i]);
        sum[i] = sum[i - 1] + e[i];
    }

    std::cout << dp() << std::endl;

    return 0;
}