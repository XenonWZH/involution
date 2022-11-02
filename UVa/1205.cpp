#include <cstdio>
#include <vector>
#include <queue>

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
        a[x] = y;
    }
};

int main() {
    int n, r;
    while (scanf("%d %d", &n, &r) != EOF && n != 0 && r != 0) {
        r--;
        std::vector<int> c(n), fa(n);
        std::priority_queue<std::pair<double, int>> q;
        long long ans = 0;

        for (int i = 0; i < n; i++) {
            scanf("%d", &c[i]);
            ans += c[i];
            if (i != r) q.push(std::make_pair(1.0 * c[i], i));
        }
        for (int i = 0; i < n - 1; i++) {
            int u, v;
            scanf("%d %d", &u, &v);
            fa[v - 1] = u - 1;
        }

        std::vector<int> size(n, 1);
        std::vector<bool> vis(n, false);
        UnionFindSet ufs;
        ufs.init(n);

        while (!q.empty()) {
            int u = q.top().second;
            q.pop();
            if (vis[u]) continue;
            vis[u] = true;

            int f = ufs.find(fa[u]);
            ans += size[f] * c[u];
            c[f] += c[u];
            size[f] += size[u];
            ufs.merge(u, f);
            if (f != r) q.push(std::make_pair(1.0 * c[f] / size[f], f));
        }

        printf("%lld\n", ans);
    }

    return 0;
}