#include <cstdio>
#include <cmath>
#include <cstring>
#include <iostream>

const int MAXN = 200000;

int n, m;
long long s, ans = 1e12;
std::pair<int, int> stone[MAXN + 1], inter[MAXN + 1];

inline long long myAbs(long long x) {
    return x > 0 ? x : -x;
}

bool check(int pos) {
    static long long preN[MAXN + 1], preV[MAXN + 1];
    long long sumAns = 0;

    memset(preN, 0, sizeof(preN));
    memset(preV, 0, sizeof(preV));

    for (int i = 1; i <= n; i++) {
        if (stone[i].first >= pos) {
            preN[i] = preN[i - 1] + 1;
            preV[i] = preV[i - 1] + stone[i].second;
        } else {
            preN[i] = preN[i - 1];
            preV[i] = preV[i - 1];
        }
    }

    for (int i = 1; i <= m; i++) {
        sumAns += (preN[inter[i].second] - preN[inter[i].first - 1]) *
                 (preV[inter[i].second] - preV[inter[i].first - 1]);
    }

    if (myAbs(sumAns - s) < ans) ans = myAbs(sumAns - s);

    if (sumAns > s) return true;
    else return false;
}

int main() {
    scanf("%d%d%lld", &n, &m, &s);

    for (int i = 1, x, y; i <= n; i++) {
        scanf("%d%d", &x, &y);
        stone[i] = std::make_pair(x, y);
    }

    for (int i = 1, x, y; i <= m; i++) {
        scanf("%d%d", &x, &y);
        inter[i] = std::make_pair(x, y);
    }


    long long l = 1, r = 1e12;
    while (l <= r) {
        long long mid = (l + r) >> 1;
        if (check(mid)) l = mid + 1;
        else r = mid - 1;
    }

    printf("%lld\n", ans);

    return 0;
}
