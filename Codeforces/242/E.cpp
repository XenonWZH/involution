#include <cstdio>

const int MAXN = 1e5;
const int LOG_MAXX = 20;

struct SegT {
    int l, r;
    SegT *lc, *rc;
    int val;
    bool tag;

    SegT(int l, int r, SegT *lc, SegT *rc) : l(l), r(r), lc(lc), rc(rc), tag(false) {}
    SegT(int l, int r, SegT *lc, SegT *rc, int val) : l(l), r(r), lc(lc), rc(rc), val(val), tag(false) {}

    void cover(const bool delta) {
        if (delta) val = r - l + 1 - val;
        tag ^= delta;
    }

    void pushDown() {
        if (tag) {
            lc->cover(tag);
            rc->cover(tag);
            tag = false;
        }
    }

    void update(const int l, const int r) {
        if (l > this->r || r < this->l) return;
        else if (l <= this->l && r >= this->r) cover(true);
        else {
            pushDown();
            lc->update(l, r);
            rc->update(l, r);
            val = lc->val + rc->val;
        }
    }

    int query(const int l, const int r) {
        if (l > this->r || r < this->l) return 0;
        else if (l <= this->l && r >= this->r) return val;
        else {
            pushDown();
            return lc->query(l, r) + rc->query(l, r);
        }
    }

    static SegT *build(const int l, const int r, int *a) {
        if (l > r) return NULL;
        else if (l == r) return new SegT(l, r, NULL, NULL, a[l]);
        else {
            const int mid = l + (r - l) / 2;
            SegT *segt = new SegT(l, r, build(l, mid, a), build(mid + 1, r, a));
            segt->val = segt->lc->val + segt->rc->val;
            return segt;
        }
    }
} *segment[LOG_MAXX + 1];

int main() {
    int n, m;
    static int a[MAXN + 1];

    scanf("%d", &n);
    for (int i = 1; i <= n; i++) scanf("%d", &a[i]);

    static int bit[MAXN + 1];
    for (int i = 0; i <= LOG_MAXX; i++) {
        for (int j = 1; j <= n; j++) bit[j] = ((a[j] >> i) & 1);
        segment[i] = SegT::build(1, n, bit);
    }

    scanf("%d", &m);
    while (m--) {
        int op;
        scanf("%d", &op);

        if (op == 1) {
            int l, r;
            scanf("%d %d", &l, &r);
            long long ans = 0;
            for (int i = 0; i <= LOG_MAXX; i++) {
                ans += (1ll << i) * segment[i]->query(l, r);
            }
            printf("%lld\n", ans);
        } else if (op == 2) {
            int l, r, x;
            scanf("%d %d %d", &l, &r, &x);
            for (int i = 0; i <= LOG_MAXX; i++) {
                if ((x >> i) & 1) {
                    segment[i]->update(l, r);
                }
            }
        }
    }

    return 0;
}