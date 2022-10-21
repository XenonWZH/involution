#include <cstdio>

const int MAXN = 500000;

struct BinaryIndexedTree {
    int a[MAXN + 2], n;

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
    int n, m;
    scanf("%d %d", &n, &m);

    bit.init(n + 1);
    int bef = 0;
    for (int i = 1; i <= n; i++) {
        int a;
        scanf("%d", &a);
        bit.update(i, a - bef);
        bef = a;
    }

    while (m--) {
        int op;
        scanf("%d", &op);
        if (op == 1) {
            int x, y, k;
            scanf("%d %d %d", &x, &y, &k);
            bit.update(x, k);
            bit.update(y + 1, -k);
        } else if (op == 2) {
            int x;
            scanf("%d", &x);
            printf("%d\n", bit.query(x));
        }
    }

    return 0;
}