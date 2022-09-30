#include <cstdio>
#include <iostream>
#include <vector>

const int MAXN = 3e5;

struct SegT {
    int l, r;
    SegT *lc, *rc;
    long long val;

    SegT(int l, int r, SegT *lc, SegT *rc) : l(l), r(r), lc(lc), rc(rc), val(0) {}

    static SegT *build(const int l, const int r) { return new SegT(l, r, NULL, NULL); }

    void update(const int pos, const long long delta) {
        if (pos > r || pos < l)
            return;
        else if (pos == l && pos == r)
            val += delta;
        else {
            int mid = (l + r) / 2;
            if (pos <= mid) {
                if (!lc) lc = build(l, mid);
                lc->update(pos, delta);
            } else {
                if (!rc) rc = build(mid + 1, r);
                rc->update(pos, delta);
            }
            val = 0;
            if (lc) val += lc->val;
            if (rc) val += rc->val;
        }
    }

    int query(const int pos) {
        if (l == r)
            return l;
        else {
            if (!lc) lc = SegT::build(l, (l + r) / 2);
            int lSize = (r - l) / 2 + 1 + lc->val;
            if (pos <= lSize)
                return lc->query(pos);
            else {
                if (!rc) rc = SegT::build((l + r) / 2 + 1, r);
                return rc->query(pos - lSize);
            }
        }
    }
} *seg[MAXN + 2];

int main() {
    int n, m, q;

    scanf("%d %d %d", &n, &m, &q);
    int max = std::max(n, m) + q;
    for (int i = 1; i <= n + 1; i++) seg[i] = SegT::build(1, max);

    static std::vector<long long> tail[MAXN + 2];
    while (q--) {
        int x, y;
        scanf("%d %d", &x, &y);

        long long res = 0, val = 0;
        if (y != m) {
            int pos = seg[x]->query(y);
            seg[x]->update(pos, -1);
            res = pos < m ? (1ll * (x - 1) * m + pos) : (tail[x][pos - m]);
            val = res;
            printf("%lld\n", res);
        }

        int pos = seg[n + 1]->query(x);
        seg[n + 1]->update(pos, -1);
        res = pos <= n ? (1ll * pos * m) : tail[n + 1][pos - n - 1];
        tail[n + 1].push_back(val ? val : res);
        if (y == m)
            printf("%lld\n", res);
        else
            tail[x].push_back(res);
    }

    return 0;
}