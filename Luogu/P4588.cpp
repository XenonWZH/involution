#include <cstdio>

const int MAXN = 1e5;

int Q, M;

struct SegT {
    int l, r;
    SegT *lc, *rc;
    long long val;

    SegT(int l, int r, SegT *lc, SegT *rc) : l(l), r(r), lc(lc), rc(rc), val(1) {}

    void update(const int pos, const long long delta) {
        if (pos > this->r || pos < this->l) return;
        else if (pos == this->l && pos == this->r) val = delta;
        else {
            lc->update(pos, delta);
            rc->update(pos, delta);
            val = lc->val * rc->val % M;
        }
    }

    long long query(const int l, const int r) {
        if (l > this->r || r < this->l) return 1;
        else if (l <= this->l && r >= this->r) return val;
        else return lc->query(l, r) * rc->query(l, r) % M;
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
    int t;

    scanf("%d", &t);

    while (t--) {
        scanf("%d %d", &Q, &M);

        segment = SegT::build(1, Q);

        for (int i = 1; i <= Q; i++) {
            int op;
            long long m;
            scanf("%d %lld", &op, &m);

            if (op == 1) segment->update(i, m);
            else if (op == 2) segment->update(m, 1);

            printf("%lld\n", segment->query(1, Q));
        }
    }

    return 0;
}