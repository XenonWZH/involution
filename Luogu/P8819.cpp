#include <cstdio>
#include <vector>
#include <random>

int main() {
    int n, m;
    scanf("%d %d", &n, &m);

    std::vector<unsigned long long> a(n + 1);
    unsigned long long target = 0;

    std::default_random_engine rng(time(nullptr));
    for (int i = 1; i <= n; i++) {
        a[i] = ((unsigned long long)rng() << 31) ^ rng();
        target += a[i];
    }

    std::vector<unsigned long long> init(n + 1);
    unsigned long long res = 0;
    for (int i = 1; i <= m; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        init[v] += a[u];
        res += a[u];
    }

    std::vector<unsigned long long> in(init);

    int q;
    scanf("%d", &q);
    while (q--) {
        int op;
        scanf("%d", &op);

        if (op == 1) {
            int u, v;
            scanf("%d %d", &u, &v);
            in[v] -= a[u];
            res -= a[u];
        } else if (op == 2) {
            int u;
            scanf("%d", &u);
            res -= in[u];
            in[u] = 0;
        } else if (op == 3) {
            int u, v;
            scanf("%d %d", &u, &v);
            in[v] += a[u];
            res += a[u];
        } else if (op == 4) {
            int u;
            scanf("%d", &u);
            res += init[u] - in[u];
            in[u] = init[u];
        }

        if (res == target) puts("YES");
        else puts("NO");
    }

    return 0;
}