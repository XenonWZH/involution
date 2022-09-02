#include <cstdio>
#include <cstring>
#include <algorithm>

const int MAXN = 500000;
const int MAXS = 10000;

struct BinaryIndexedTree {
    int a[MAXS + 1], n;

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

    int query(const int pos) {
        int ans = 0;
        for (int i = pos; i > 0; i -= lowbit(i)) ans += a[i];
        return ans;
    }
} bit;

int main() {
    int n, k, s;
    static int a[MAXN + 1], b[MAXN + 1];

    scanf("%d %d %d", &n, &k, &s);
    for (int i = 1; i <= n; i++) scanf("%d", &a[i]);

    bit.init(s);
    static int rank1[MAXN + 1], rank2[MAXN + 1];
    for (int i = 1; i <= k; i++) {
        scanf("%d", &b[i]);
        bit.update(b[i], 1);
        rank1[i] = bit.query(b[i]);
        rank2[i] = bit.query(b[i] - 1);
    }

    bit.init(s);
    static int fail[MAXN + 1];
    fail[1] = 0;
    for (int i = 2, j = 0; i <= k; i++) {
        bit.update(b[i], 1);
        while (j && (bit.query(b[i]) != rank1[j + 1] || bit.query(b[i] - 1) != rank2[j + 1])) {
            for (int l = i - j; l < i - fail[j]; l++) bit.update(b[l], -1);
            j = fail[j];
        }
        if (bit.query(b[i]) == rank1[j + 1] && bit.query(b[i] - 1) == rank2[j + 1]) j++;
        fail[i] = j;
    }

    bit.init(s);
    static int ans[MAXN + 1];
    int tot = 0;
    for (int i = 1, j = 0; i <= n; i++) {
        bit.update(a[i], 1);
        while (j && (bit.query(a[i]) != rank1[j + 1] || bit.query(a[i] - 1) != rank2[j + 1])) {
            for (int l = i - j; l < i - fail[j]; l++) bit.update(a[l], -1);
            j = fail[j];
        }
        if (bit.query(a[i]) == rank1[j + 1] && bit.query(a[i] - 1) == rank2[j + 1]) j++;
        if (j == k) {
            ans[++tot] += i - k + 1;
            for (int l = i - j + 1; l <= i - fail[j]; l++) bit.update(a[l], -1);
            j = fail[j];
        }
    }

    printf("%d\n", tot);
    for (int i = 1; i <= tot; i++) printf("%d\n", ans[i]);

    return 0;
}