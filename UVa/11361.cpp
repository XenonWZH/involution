#include <cstdio>
#include <cstring>

const int MAXK = 100;

int k;
long long f[11][MAXK + 1][MAXK + 1];
bool vis[11][MAXK + 1][MAXK + 1];

inline long long pow(const int n, const int k) {
    long long ans = 1;
    for (long long num = n, t = k; t; num = num * num, t >>= 1) {
        if (t & 1) {
            ans = ans * num;
        }
    }
    return ans;
}

inline int length(int x) {
    int ans = 0;
    do ans++; while (x /= 10);
    return ans;
}

inline int sum(int x) {
    int ans = 0;
    do ans += x % 10; while (x /= 10);
    return ans;
}

inline int chkAdd(int a, int b) {
    return (a % b + b) % b;
}

int dp(int x, int m1, int m2) {
    long long &ans = f[x][m1][m2];
    if (vis[x][m1][m2]) return ans;
    vis[x][m1][m2] = true;

    ans = 0;
    if (x == 1) {
        for (int i = 0; i <= 9; i++) {
            if (i % k == m1 && i % k == m2) ans++;
        }
    } else {
        for (int i = 0; i <= 9; i++) {
            ans += dp(x - 1, chkAdd(m1 - i, k), chkAdd(m2 - i * pow(10, x - 1) % k, k));
        }
    }

    return ans;
}

int solve(int x, int m1, int m2) {
    int ans = 0;
    if (x < 10) {
        for (int i = 0; i <= x; i++) {
            if (i % k == m1 && i % k == m2) ans++;
        }
    } else {
        int n = length(x), first = x / pow(10, n - 1);
        for (int i = 0; i < first; i++) {
            ans += dp(n - 1, chkAdd(m1 - i, k), chkAdd(m2 - pow(10, n - 1) * i, k));
        }
        ans += solve(x % pow(10, n - 1), chkAdd(m1 - first, k), chkAdd(m2 - pow(10, n - 1) * first, k));
    }

    return ans;
}

int main() {
    int t;
    scanf("%d", &t);

    for (int i = 0; i < t; i++) {
        memset(f, 0, sizeof(f));
        memset(vis, false, sizeof(vis));

        int a, b;
        scanf("%d %d %d", &a, &b, &k);

        if (k >= 100) puts("0");
        else printf("%d\n", solve(b, 0, 0) - solve(a - 1, 0, 0));
    }

    return 0;
}