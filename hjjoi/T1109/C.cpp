#include <cstdio>
#include <cstring>
#include <algorithm>
#include <map>

const int MAXN = 30000;
const int MAXM = 100000;

struct BinaryIndexedTree {
    long long a[MAXM + 1];
    int n;

    void init(const int n) {
        memset(a, 0, sizeof(a));
        this->n = n;
    }

    static int lowbit(const int x) {
        return x & -x;
    }

    void update(const int pos, const int delta) {
        for (int i = pos; i <= n; i += lowbit(i)) a[i] += delta;
    }

    long long query(const int pos) {
        long long ans = 0;
        for (int i = pos; i > 0; i -= lowbit(i)) ans += a[i];
        return ans;
    }
} bit;

struct Query {
    int l, r, id;
} querys[MAXM + 1];

int n, m;
long long a[MAXN + 1];
long long ans[MAXM + 1];
std::map<long long, int> pos;

bool cmp(Query a, Query b) {
    return a.r < b.r;
}

int main() {
    int t;

    scanf("%d", &t);

    while (t--) {
        memset(ans, 0, sizeof(ans));
        pos.clear();

        scanf("%d", &n);
        for (int i = 1; i <= n; i++) scanf("%lld", &a[i]);
        scanf("%d", &m);

        bit.init(n);

        for (int i = 1; i <= m; i++) {
            scanf("%d %d", &querys[i].l, &querys[i].r);
            querys[i].id = i;
        }
        std::sort(querys + 1, querys + m + 1, cmp);

        int left = 1;
        for (int i = 1; i <= m; i++) {
            for (int j = left; j <= querys[i].r; j++) {
                if (pos.count(a[j])) bit.update(pos[a[j]], -a[j]);
                pos[a[j]] = j;
                bit.update(j, a[j]);
            }

            left = querys[i].r + 1;
            ans[querys[i].id] = bit.query(querys[i].r) - bit.query(querys[i].l - 1);
        }

        for (int i = 1; i <= m; i++) printf("%lld\n", ans[i]);
    }

    return 0;
}