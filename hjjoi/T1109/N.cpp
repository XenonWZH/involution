// 为什么用指针写即使加了内存池，常数还是那么大过不了啊 QAQ

#include <cstdio>
#include <climits>
#include <algorithm>

const int MAXN = 1e6;
const int MAXN_LOG = 32;

struct SegT {
    struct Node {
        int l, r;
        int lc, rc;
        int val;

        Node() {}
        Node(int l, int r, int lc, int rc) : l(l), r(r), lc(lc), rc(rc) {}
        Node(int l, int r, int lc, int rc, const int &val) : l(l), r(r), lc(lc), rc(rc), val(val) {}
    } pool[MAXN_LOG * MAXN];

    int segt[MAXN + 1], size;

    int update(int self, int pos, int newVal) {
        if (pos < pool[self].l || pos > pool[self].r) return self;
        else if (pool[self].l == pool[self].r) {
            pool[size] = Node(pool[self].l, pool[self].r, -1, -1, newVal);
            return size++;
        } else {
            pool[size] = Node(pool[self].l, pool[self].r, update(pool[self].lc, pos, newVal), update(pool[self].rc, pos, newVal));
            return size++;
        }
    }

    int query(int self, int pos) {
        if (pos > pool[self].r || pos < pool[self].l) return 0;
        else if (pos == pool[self].l && pos == pool[self].r) return pool[self].val;
        else return query(pool[self].lc, pos) + query(pool[self].rc, pos);
    }

    int build(int l, int r, int *a) {
        if (l == r) {
            pool[size] = Node(l, r, -1, -1, a[l]);
            return size++;
        } else {
            int mid = l + (r - l) / 2;
            pool[size] = Node(l, r, build(l, mid, a), build(mid + 1, r, a));
            return size++;
        }
    }
} segment;

int main() {
    int n, m;
    static int a[MAXN + 1];

    scanf("%d %d", &n, &m);
    for (int i = 1; i <= n; i++) scanf("%d", &a[i]);

    segment.segt[0] = segment.build(1, n, a);

    for (int i = 1; i <= m; i++) {
        int v, op, loc;
        scanf("%d %d %d", &v, &op, &loc);
        if (op == 1) {
            int val;
            scanf("%d", &val);
            segment.segt[i] = segment.update(segment.segt[v], loc, val);
        } else {
            printf("%d\n", segment.query(segment.segt[v], loc));
            segment.segt[i] = segment.segt[v];
        }
    }

    return 0;
}