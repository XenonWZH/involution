#include <cstdio>
#include <climits>
#include <iostream>
#include <vector>
#include <queue>

int main() {
    int n;
    scanf("%d", &n);

    std::vector<int> d(n);
    for (int i = 0; i < n; i++) scanf("%d", &d[i]);

    int q;
    scanf("%d", &q);

    while (q--) {
        int k;
        scanf("%d", &k);

        std::vector<int> f(n);
        f[0] = 0;
        std::deque<int> mq;
        mq.push_back(0);

        for (int i = 1; i < n; i++) {
            while (mq.front() < i - k) mq.pop_front();
            f[i] = f[mq.front()] + (d[mq.front()] <= d[i]);
            while (!mq.empty() && (f[mq.back()] > f[i] || (f[mq.back()] == f[i] && d[mq.back()] <= d[i]))) mq.pop_back();
            mq.push_back(i);
        }

        printf("%d\n", f[n - 1]);
    }

    return 0;
}