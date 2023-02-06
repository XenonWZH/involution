#include <cstdio>
#include <vector>

const int MAXN = 5e5;
const int MAXQ = 5e6;
const int LOG_MAXN = 20;

std::vector<int> G[MAXN + 1];
int fa[MAXN + 1][LOG_MAXN + 1], dep[MAXN + 1];

void prepare(int u, int f) {
    fa[u][0] = f;
    dep[u] = dep[f] + 1;
    for (int i = 1; i < LOG_MAXN; i++) fa[u][i] = fa[fa[u][i - 1]][i - 1];
    for (int v : G[u]) prepare(v, u);
}

int getFa(int u, int k) {
    for (int i = 0; k; k >>= 1, i++) {
        if (k & 1) {
            u = fa[u][i];
        }
    }
    return u;
}

unsigned s;

inline unsigned get(unsigned x) {
    x ^= x << 13;
    x ^= x >> 17;
    x ^= x << 5;
    return s = x;
}

int main() {
    int n, q;
    scanf("%d %d %d", &n, &q, &s);

    int root = 0;
    for (int i = 1; i <= n; i++) {
        int fa;
        scanf("%d", &fa);
        if (fa) G[fa].push_back(i);
        else root = i;
    }

    prepare(root, 0);

    static unsigned ans[MAXQ + 1];
    for (unsigned i = 1; i <= q; i++) {
        unsigned x = (get(s) ^ ans[i - 1]) % n + 1;
        unsigned k = (get(s) ^ ans[i - 1]) % dep[x];
        ans[i] = getFa(x, k);
    }

    long long xxor = 0;
    for (int i = 1; i <= q; i++) xxor ^= 1ll * i * ans[i];
    printf("%lld\n", xxor);

    return 0;
}