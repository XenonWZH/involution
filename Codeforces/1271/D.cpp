#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>

const int MAXN = 5000;

int main() {
    int n, m, k;
    scanf("%d %d %d", &n, &m, &k);

    static int r[MAXN], a[MAXN], b[MAXN], c[MAXN];
    for (int i = 0; i < n; i++) scanf("%d %d %d", &a[i], &b[i], &c[i]);
    for (int i = 0; i < n; i++) r[i] = i;
    for (int i = 0; i < m; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        u--;
        v--;
        r[v] = std::max(r[v], u);
    }

    static std::vector<int> e[MAXN];
    for (int i = 0; i < n; i++) e[r[i]].push_back(i);

    static int f[MAXN + 1];
    memset(f, -1, sizeof(f));
    f[k] = 0;
    for (int i = 0; i < n; i++) {
        for (int j = MAXN - b[i]; j >= a[i]; j--) f[j + b[i]] = f[j];
        for (int j = 0; j < a[i] + b[i]; j++) f[j] = -1;
        for (int j : e[i]) {
            for (int k = 0; k < MAXN; k++) {
                if (f[k + 1] != -1) {
                    f[k] = std::max(f[k], f[k + 1] + c[j]);
                }
            }
        }
    }

    printf("%d\n", *std::max_element(f, f + MAXN + 1));

    return 0;
}