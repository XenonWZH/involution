#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>

const int MAXN = 11;

std::vector<int> a;

long long f[MAXN][11][10][2][2][2][2];
bool vis[MAXN][11][10][2][2][2][2];

long long dp(int n, int limit, int last, bool equal, bool flag, bool four, bool eight) {
    long long &ans = f[n][limit][last][equal][flag][four][eight];
    if (vis[n][limit][last][equal][flag][four][eight]) return ans;
    vis[n][limit][last][equal][flag][four][eight] = true;

    ans = 0;
    if (n == 1) {
        for (int i = 0; i <= std::min(limit, 9); i++) {
            if (i == 4 && eight) continue;
            if (i == 8 && four) continue;

            if (flag || (equal && i == last)) ans++;
        }
    } else {
        int &next = a[MAXN - n + 1];
        for (int i = 0; i <= std::min(limit, 9); i++) {
            if (i == 4 && eight) continue;
            if (i == 8 && four) continue;

            int t;
            if (i < limit || limit > 9) {
                t = 10;
            } else t = next;

            ans += dp(n - 1, t, i, i == last, flag || (equal && i == last), four || (i == 4), eight || (i == 8));
        }
    }

    return ans;
}

long long solve(long long num) {
    if (num < 1e10) return 0;

    a.clear();
    for (; num; num /= 10) a.push_back(num % 10);
    std::reverse(a.begin(), a.end());

    memset(f, 0, sizeof(f));
    memset(vis, false, sizeof(vis));

    int &limit = a[0];
    long long ans = 0;
    for (int i = 1; i <= limit; i++) {
        int t;
        if (i < limit) t = 10;
        else t = a[1];
        ans += dp(MAXN - 1, t, i, false, false, i == 4, i == 8);
    }

    return ans;
}

int main() {
    long long l, r;

    scanf("%lld %lld", &l, &r);

    printf("%lld\n", solve(r) - solve(l - 1));

    return 0;
}