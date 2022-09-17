#include <cstdio>
#include <climits>
#include <iostream>
#include <queue>
#include <algorithm>

int main() {
    int n, m, q, u, v, t;

    scanf("%d %d %d %d %d %d", &n, &m, &q, &u, &v, &t);

    static std::priority_queue<long long> a;
    for (int i = 1; i <= n; i++) {
        long long x;
        scanf("%lld", &x);
        a.push(x);
    }

    static std::queue<long long> q1, q2;
    int delta = 0;
    for (int i = 1; i <= m; i++) {
        long long maxx = a.empty() ? LLONG_MIN : a.top();
        int w = 0;
        if (!q1.empty() && maxx < q1.front()) {
            maxx = q1.front();
            w = 1;
        }
        if (!q2.empty() && maxx < q2.front()) {
            maxx = q2.front();
            w = 2;
        }
        if (w == 1) q1.pop();
        else if (w == 2) q2.pop();
        else a.pop();
        maxx += delta;
        q1.push(maxx * u / v - delta - q);
        q2.push(maxx - maxx * u / v - delta - q);
        delta += q;
        if (i % t == 0) printf("%lld ", maxx);
    }
    putchar('\n');

    for (int i = 1; i <= n + m; i++) {
        long long maxx = a.empty() ? LLONG_MIN : a.top();
        int w = 0;
        if (!q1.empty() && maxx < q1.front()) {
            maxx = q1.front();
            w = 1;
        }
        if (!q2.empty() && maxx < q2.front()) {
            maxx = q2.front();
            w = 2;
        }
        if (w == 1) q1.pop();
        else if (w == 2) q2.pop();
        else a.pop();
        if (i % t == 0) printf("%lld ", maxx + delta);
    }
    putchar('\n');

    return 0;
}