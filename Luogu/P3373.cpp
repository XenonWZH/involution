#include <cstdio>

int p;

struct SegT {
    int l, r;
    SegT *lc, *rc;
    long long val, tagMul, tagPlus;

    SegT(int l, int r, SegT *lc, SegT *rc) : l(l), r(r), lc(lc), rc(rc), tagMul(1), tagPlus(0) {}

    void cover(int type, long long tag) {
        if (type == 1) {
            val = val * tag % p;
            tagMul = tagMul * tag % p;
            tagPlus = tagPlus * tag % p;
        } else if (type == 2) {
            val = (val + (r - l + 1) * tag) % p;
            tagPlus = (tagPlus + tag) % p;
        }
    }

    void pushDown() {
        if (tagMul != 1) {
            lc->cover(1, tagMul);
            rc->cover(1, tagMul);
            tagMul = 1;
        }
        if (tagPlus != 0) {
            lc->cover(2, tagPlus);
            rc->cover(2, tagPlus);
            tagPlus = 0;
        }
    }

    void update(int l, int r, int type, long long delta) {
        if (r < this->l || l > this->r) return;
        else if (l <= this->l && r >= this->r) cover(type, delta);
        else {
            pushDown();
            lc->update(l, r, type, delta);
            rc->update(l, r, type, delta);
            val = (lc->val + rc->val) % p;
        }
    }

    long long query(int l, int r) {
        if (r < this->l || l > this->r) return 0;
        else if (l <= this->l && r >= this->r) return val;
        else {
            pushDown();
            return (lc->query(l, r) + rc->query(l, r)) % p;
        }
    }

    static SegT *build(int l, int r) {
        if (l > r) return nullptr;
        else if (l == r) return new SegT(l, r, nullptr, nullptr);
        else {
            int mid = (l + r) / 2;
            return new SegT(l, r, build(l, mid), build(mid + 1, r));
        }
    }
} *segment;

int main() {
    int n, m;
    scanf("%d %d %d", &n, &m, &p);

    segment = SegT::build(1, n);
    for (int i = 1; i <= n; i++) {
        int a;
        scanf("%d", &a);
        segment->update(i, i, 2, a);
    }

    while (m--) {
        int op, x, y, k;
        scanf("%d %d %d", &op, &x, &y);

        if (op <= 2) {
            scanf("%d", &k);
            segment->update(x, y, op, k);
        } else printf("%lld\n", segment->query(x, y));
    }

    return 0;
}