#include <cstdio>

struct SegT {
    int l, r;
    SegT *lc, *rc;
    int val, tag;

    SegT(int l, int r, SegT *lc, SegT *rc) : l(l), r(r), lc(lc), rc(rc), val(0) {}

    void cover(const bool delta) {
        if (delta) val = r - l + 1 - val;
        tag ^= delta;
    }

    void pushDown() {
        if (tag) {
            lc->cover(tag);
            rc->cover(tag);
            tag = 0;
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

    static SegT *build(const int l, const int r) {
        if (l > r) return nullptr;
        else if (l == r) return new SegT(l, r, nullptr, nullptr);
        else {
            const int mid = l + (r - l) / 2;
            return new SegT(l, r, build(l, mid), build(mid + 1, r));
        }
    }
} *segment;

int main() {
    int n, m;

    scanf("%d %d", &n, &m);
    segment = SegT::build(1, n);

    while (m--) {
        int c, a, b;
        scanf("%d %d %d", &c, &a, &b);

        if (c == 0) segment->update(a, b);
        else printf("%d\n", segment->query(a, b));
    }

    return 0;
}