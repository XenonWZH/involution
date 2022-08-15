#include <cstdio>
#include <cmath>

const int MAXN = 5e5;

long long gcd(long long a, long long b) {
    a = std::abs(a), b = std::abs(b);
    return b == 0 ? a : gcd(b, a % b);
}

struct SegT {
    int l, r;
    SegT *lc, *rc;
    long long val;

    SegT(int l, int r, SegT *lc, SegT *rc) : l(l), r(r), lc(lc), rc(rc), val(0) {}
    SegT(int l, int r, SegT *lc, SegT *rc, long long val) : l(l), r(r), lc(lc), rc(rc), val(val) {}

    void update(const int pos, const long long delta) {
        if (this->l == this->r) val += delta;
        else {
            const int mid = this->l + (this->r - this->l) / 2;
            if (pos <= mid) lc->update(pos, delta);
            else rc->update(pos, delta);
            val = gcd(lc->val, rc->val);
        }
    }

    long long query(const int l, const int r) {
        if (l <= this->l && r >= this->r) return std::abs(val);
        else {
            const int mid = this->l + (this->r - this->l) / 2;
            long long dat = 0;
            if (l <= mid) dat = gcd(dat, lc->query(l, r));
            if (r > mid) dat = gcd(dat, rc->query(l, r));
            return std::abs(dat);
        }
    }

    static SegT *build(const int l, const int r, long long *a) {
        if (l == r) return new SegT(l, r, nullptr, nullptr, a[l]);
        else {
            const int mid = l + (r - l) / 2;
            SegT *segt = new SegT(l, r, build(l, mid, a), build(mid + 1, r, a));
            segt->val = gcd(segt->lc->val, segt->rc->val);
            return segt;
        }
    }
} *segment;

struct BinaryIndexedTree {
    long long a[MAXN + 2];
    int n;

    void init(const int n) {
        this->n = n;
    }

    static int lowbit(const int x) {
        return x & -x;
    }

    void update(const int pos, const long long delta) {
        for (int i = pos; i <= n; i += lowbit(i)) a[i] += delta;
    }

    long long query(const int pos) {
        long long ans = 0;
        for (int i = pos; i > 0; i -= lowbit(i)) ans += a[i];
        return ans;
    }
} bit;

int main() {
#ifndef DBG
    freopen("section.in", "r", stdin);
    freopen("section.out", "w", stdout);
#endif

    int n, m;
    static long long a[MAXN + 1];
    static long long diff[MAXN + 1];

    scanf("%d %d", &n, &m);
    for (int i = 1; i <= n; i++) {
        scanf("%lld", &a[i]);
        diff[i] = a[i] - a[i - 1];
    }

    segment = SegT::build(1, n, diff);
    bit.init(n + 1);

    while (m--) {
        char cmd[2];
        scanf("%s", cmd);
        if (cmd[0] == 'Q') {
            int l, r;
            scanf("%d %d", &l, &r);
            long long al = a[l] + bit.query(l);
            long long val = l < r ? segment->query(l + 1, r) : 0;
            printf("%lld\n", gcd(al, val));
        } else {
            int l, r;
            long long delta;
            scanf("%d %d %lld", &l, &r, &delta);
            segment->update(l, delta);
            if (r < n) segment->update(r + 1, -delta);
            bit.update(l, delta);
            bit.update(r + 1, -delta);
        }
    }

#ifndef DBG
    fclose(stdin);
    fclose(stdout);
#endif

    return 0;
}