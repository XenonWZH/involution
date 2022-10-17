#include <cstdio>
#include <cmath>
#include <iostream>
#include <vector>

const int MAXN = 5000;

struct UnionFindSet {
    std::vector<int> a;

    void init(int n) {
        a.resize(n);
        for (int i = 0; i < n; i++) a[i] = i;
    }

    int find(int x) {
        return x == a[x] ? x : (a[x] = find(a[x]));
    }

    void merge(int x, int y) {
        a[find(x)] = find(y);
    }
} ufs;

int main() {
    int n;
    scanf("%d", &n);
    ufs.init(n);

    std::vector<long long> a(n);
    for (int i = 0; i < n; i++) scanf("%lld", &a[i]);

    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (a[i] * a[j] > 0) {
                long long sq = sqrt(a[i] * a[j]);
                if (sq * sq == a[i] * a[j]) ufs.merge(i, j);
            }
        }
    }

    std::vector<long long> ans(n + 1);
    for (int i = 0; i < n; i++) {
        int tot = 0;
        std::vector<bool> vis(n + 1);
        for (int j = i; j < n; j++) {
            if (a[j] == 0) ans[std::max(1, tot)]++;
            else {
                if (!vis[ufs.find(j)]) vis[ufs.find(j)] = true, tot++;
                ans[tot]++;
            }
        }
    }

    for (int i = 1; i <= n; i++) printf("%lld ", ans[i]);
    putchar('\n');
}