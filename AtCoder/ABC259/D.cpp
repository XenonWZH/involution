#include <cstdio>
#include <cstring>
#include <cmath>
#include <queue>
#include <vector>
 
const int MAXN = 3000;
 
int n;
long long sx, sy, tx, ty;
long long x[MAXN], y[MAXN];
unsigned long long r[MAXN];

struct UFS {
    int fa[MAXN + 1];

    void init(int n) {
        for (int i = 0; i < n; i++) fa[i] = i;
    }

    int find(int x) { return x == fa[x] ? x : fa[x] = find(fa[x]); }

    void merge(int x, int y) { fa[find(x)] = find(y); }
} ufs;

inline unsigned long long myPow(long long a) {
    return a * a;
}

inline unsigned long long distance2(long long x1, long long y1, long long x2, long long y2) {
    return myPow(x1 - x2) + myPow(y1 - y2);
}
 
int solve() {
    // static bool vis[MAXN];
    // memset(vis, false, sizeof(vis));
 
    // static std::queue<int> q;
    // for (int i = 0; i < n; i++) {
    //     if (distance2(sx, sy, x[i], y[i]) == myPow(r[i])) {
    //         q.push(i);
    //         vis[i] = true;
    //     }
    // }
 
    static std::vector<int> bef, ans;
    for (int i = 0; i < n; i++) {
        if (distance2(sx, sy, x[i], y[i]) == myPow(r[i])) {
            bef.push_back(i);
        }
    }
    for (int i = 0; i < n; i++) {
        if (distance2(tx, ty, x[i], y[i]) == myPow(r[i])) {
            ans.push_back(i);
        }
    }

    ufs.init(n);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (ufs.find(i) != ufs.find(j) && distance2(x[i], y[i], x[j], y[j]) <= myPow(r[i] + r[j]) && distance2(x[i], y[i], x[j], y[j]) >= myPow(r[i] - r[j])) {
                ufs.merge(i, j);
            }
        }
    }

    for (int eBef : bef) {
        for (int eAns : ans) {
            if (ufs.find(eBef) == ufs.find(eAns)) {
                return true;
            }
        }
    }

    return false;
 
    // while (!q.empty()) {
    //     int u = q.front();
    //     for (int i = 0; i < n; i++) {
    //         if (!vis[i] && distance2(x[u], y[u], x[i], y[i]) <= myPow(r[u] + r[i]) && distance2(x[u], y[u], x[i], y[i]) >= myPow(r[u] - r[i])) {
    //             for (int each : ans) {
    //                 if (each == i) {
    //                     return true;
    //                 }
    //             }
    //             q.push(i);
    //             vis[i] = true;
    //         }
    //     }
 
    //     q.pop();
    // }
 
    // return false;
}
 
int main() {
    scanf("%d\n%lld %lld %lld %lld", &n, &sx, &sy, &tx, &ty);
    for (int i = 0; i < n; i++) {
        scanf("%lld %lld %llu", &x[i], &y[i], &r[i]);
    }
 
    puts(solve() ? "Yes" : "No");
 
    return 0;
}