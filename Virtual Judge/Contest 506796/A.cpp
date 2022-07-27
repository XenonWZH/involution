#include <cstdio>

const int MAXN = 8000;

struct BinaryIndexedTree {
    int a[MAXN + 1], n;

    void init(const int n) {
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
    int n;
    static int cow[MAXN];

    scanf("%d", &n);

    cow[1] = 0;
    for (int i = 2; i <= n; i++) {
        scanf("%d", &cow[i]);
    }

    bit.init(n);

    static int ans[MAXN + 1];
    for (int i = n; i >= 1; i--) {
        int l = 1, r = n;
        while (l < r) {
            int mid = (l + r + 1) >> 1;
            if (bit.query(mid - 1) + cow[i] >= mid - 1) l = mid;
            else r = mid - 1;
        }

        ans[i] = l;
        bit.update(ans[i], 1);
    }

    for (int i = 1; i <= n; i++) {
        printf("%d\n", ans[i]);
    }

    return 0;
}