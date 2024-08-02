#include <bits/stdc++.h>

typedef long long ll;

ll p;

struct SegT {
    int l, r;
    SegT *lc, *rc;
    ll val, tagP, tagM;

    SegT(const int l, const int r, SegT *lc, SegT *rc) : l(l), r(r), lc(lc), rc(rc), val(0), tagP(0), tagM(1) {}

    void coverP(const ll delta) {
        val = (delta * (r - l + 1) % p + val) % p;
        tagP = (tagP + delta) % p;
    }

    void coverM(const ll delta) {
        val = delta * val % p;
        tagM = tagM * delta % p;
        tagP = tagP * delta % p;
    }

    void pushDown() {
        if (tagM != 1) {
            if (lc) lc->coverM(tagM);
            if (rc) rc->coverM(tagM);
            tagM = 1;
        }
        if (tagP) {
            if (lc) lc->coverP(tagP);
            if (rc) rc->coverP(tagP);
            tagP =  0;
        }
    }

    void updateP(const int l, const int r, const ll delta) {
        if (l > this->r || r < this->l) return;
        else if (l <= this->l && r >= this->r) coverP(delta);
        else {
            pushDown();
            lc->updateP(l, r, delta);
            rc->updateP(l, r, delta);
            val = (lc->val + rc->val) % p;
        }
    }

    void updateM(const int l, const int r, const ll delta) {
        if (l > this->r || r < this->l) return;
        else if (l <= this->l && r >= this->r) coverM(delta);
        else {
            pushDown();
            lc->updateM(l, r, delta);
            rc->updateM(l, r, delta);
            val = (lc->val + rc->val) % p;
        }
    }

    ll query(const int l, const int r) {
        if (l > this->r || r < this->l) return 0;
        else if (l <= this->l && r >= this->r) return val;
        else {
            pushDown();
            return (lc->query(l, r) + rc->query(l, r)) % p;
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
    int n;
    scanf("%d %lld", &n, &p);

    segment = SegT::build(1, n);

    for (int i = 1; i <= n; i++) {
        ll a;
        scanf("%lld", &a);
        segment->updateP(i, i, a);
    }

    int m;
    scanf("%d", &m);

    while (m--) {
        int op;
        scanf("%d", &op);

        int t, g;
        ll c;

        switch (op) {
        case 1:
            scanf("%d %d %lld", &t, &g, &c);
            segment->updateM(t, g, c);
            break;
        case 2:
            scanf("%d %d %lld", &t, &g, &c);
            segment->updateP(t, g, c);
            break;
        case 3:
            scanf("%d %d", &t, &g);
            printf("%lld\n", segment->query(t, g));
            break;
        }
    }

    return 0;
}