#include <cstdio>
#include <climits>
#include <algorithm>
#include <vector>

const int MAXN = 600;
const int INF = INT_MAX / 10;

int a[MAXN + 1], b[MAXN + 1], d[MAXN + 1], n, f[MAXN + 1][MAXN + 1];

int dp(int l, int r) {
    if (l > r) return 0;
    if (f[l][r] != -1) return f[l][r];
    int &ans = f[l][r];
    ans = INF;

    int maxd = -1, maxpos = -1;
    for (int i = 1; i <= n; ++i) {
        if (l <= a[i] && b[i] <= r) {
            if (d[i] > maxd) {
                maxd = d[i];
                maxpos = i;
            }
        }
    }

    if (maxd == -1) return ans = 0;
    for (int i = a[maxpos]; i <= b[maxpos]; ++i) {
        ans = std::min(ans, dp(l, i - 1) + dp(i + 1, r));
    }

    ans = ans + maxd;
    return ans;
}

int main() {
    int t;

    scanf("%d", &t);

    while (t--) {
        static std::vector<int> mp;
        mp.clear();

        scanf("%d", &n);
        for (int i = 1; i <= n; i++) {
            scanf("%d %d %d", &a[i], &b[i], &d[i]);
            mp.push_back(a[i]);
            mp.push_back(b[i]);
        }

        std::sort(mp.begin(), mp.end());
        mp.erase(unique(mp.begin(), mp.end()), mp.end());
        int size = mp.size();
         for (int i = 1; i <= n; ++i) {
            a[i] = lower_bound(mp.begin(), mp.end(), a[i]) - mp.begin() + 1;
            b[i] = lower_bound(mp.begin(), mp.end(), b[i]) - mp.begin() + 1;
        }

        for (int i = 1; i <= size; i++) {
            for (int j = 1; j <= size; j++) {
                f[i][j] = -1;
            }
        }

        printf("%d\n", dp(1, size));
    }

    return 0;
}