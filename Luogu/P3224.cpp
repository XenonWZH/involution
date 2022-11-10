#include <cstdio>
#include <vector>

struct SegT {
    int l, r;
    SegT *lc, *rc;
    std::pair<int, int> val;

    SegT(int l, int r, SegT *lc, SegT *rc) : l(l), r(r), lc(lc), rc(rc) {}

    static SegT *build(const int l, const int r) {
        if (l > r) return nullptr;
        else return new SegT(l, r, nullptr, nullptr);
    }

    void update(const int pos, const std::pair<int, int> delta) {
        if (pos < l || pos > r) return;
        else if (pos == l && pos == r) val = delta;
        else {
            const int mid = l + (r - l) / 2;
            if (pos <= mid) {
                if (!lc) lc = build(l, mid);
                lc->update(pos, delta);
            } else {
                if (!rc) rc = build(mid + 1, r);
                rc->update(pos, delta);
            }
            val.first = (lc ? lc->val.first : 0) + (rc ? rc->val.first : 0);
        }
    }

    int query(int pos) {
        if (pos == 1 && l == r) return val.second;
        if (lc) {
            if (pos <= lc->val.first) return lc->query(pos);
            pos -= lc->val.first;
        }
        return rc ? rc->query(pos) : -1;
    }

    static SegT *merge(SegT *u, SegT *v) {
        if (!u) return v;
        if (!v) return u;

        u->lc = merge(u->lc, v->lc);
        u->rc = merge(u->rc, v->rc);
        u->val.first = (u->lc ? u->lc->val.first : 0) + (u->rc ? u->rc->val.first : 0);

        return u;
    }
};

struct UnionFindSet {
    std::vector<int> a;

    void init(int n) {
        a.resize(n + 1);
        for (int i = 1; i <= n; i++) a[i] = i;
    }

    int find(int x) {
        return x == a[x] ? x : (a[x] = find(a[x]));
    }

    void merge(int x, int y) {
        a[find(x)] = find(y);
    }
} ufs;

int main() {
    int n, m;
    scanf("%d %d", &n, &m);

    ufs.init(n);
    std::vector<SegT *> segment(n + 1);
    for (int i = 1; i <= n; i++) {
        int p;
        segment[i] = SegT::build(1, n);
        scanf("%d", &p);
        segment[i]->update(p, std::make_pair(1, i));
    }

    while (m--) {
        int u, v;
        scanf("%d %d", &u, &v);
        if (ufs.find(u) != ufs.find(v)) {
            segment[ufs.find(u)] = SegT::merge(segment[ufs.find(u)], segment[ufs.find(v)]);
            ufs.merge(v, u);
        }
    }

    int q;
    scanf("%d", &q);
    while (q--) {
        char op[2];
        int x, y;
        scanf("%s %d %d", op, &x, &y);

        if (op[0] == 'Q') printf("%d\n", segment[ufs.find(x)]->query(y));
        else {
            if (ufs.find(x) != ufs.find(y)) {
                segment[ufs.find(x)] = SegT::merge(segment[ufs.find(x)], segment[ufs.find(y)]);
                ufs.merge(y, x);
            }
        }
    }

    return 0;
}