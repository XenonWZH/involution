#include <bits/stdc++.h>

const int MAXN = 1e5;

struct SegTMin {
    int l, r;
    SegTMin *lc, *rc;
    long long val;

    SegTMin(int l, int r, SegTMin *lc, SegTMin *rc) : l(l), r(r), lc(lc), rc(rc) {}
    SegTMin(int l, int r, SegTMin *lc, SegTMin *rc, long long val) : l(l), r(r), lc(lc), rc(rc), val(val) {}

    long long query(const int l, const int r) {
        if (l > this->r || r < this->l) return INT_MAX;
        else if (l <= this->l && r >= this->r) return val;
        else return std::min(lc->query(l, r), rc->query(l, r));
    }

    static SegTMin *build(const int l, const int r, long long *a) {
        if (l == r) return new SegTMin(l, r, nullptr, nullptr, a[l]);
        else {
            const int mid = l + (r - l) / 2;
            SegTMin *segt = new SegTMin(l, r, build(l, mid, a), build(mid + 1, r, a));
            segt->val = std::min(segt->lc->val, segt->rc->val);
            return segt;
        }
    }
} *segMinA, *segMinB, *segMinPA, *segMinMA;

struct SegTMax {
    int l, r;
    SegTMax *lc, *rc;
    long long val;

    SegTMax(int l, int r, SegTMax *lc, SegTMax *rc) : l(l), r(r), lc(lc), rc(rc) {}
    SegTMax(int l, int r, SegTMax *lc, SegTMax *rc, long long val) : l(l), r(r), lc(lc), rc(rc), val(val) {}

    long long query(const int l, const int r) {
        if (l > this->r || r < this->l) return INT_MIN;
        else if (l <= this->l && r >= this->r) return val;
        else return std::max(lc->query(l, r), rc->query(l, r));
    }

    static SegTMax *build(const int l, const int r, long long *a) {
        if (l == r) return new SegTMax(l, r, nullptr, nullptr, a[l]);
        else {
            const int mid = l + (r - l) / 2;
            SegTMax *segt = new SegTMax(l, r, build(l, mid, a), build(mid + 1, r, a));
            segt->val = std::max(segt->lc->val, segt->rc->val);
            return segt;
        }
    }
} *segMaxA, *segMaxB;

int main() {
    int n, m, q;
    scanf("%d %d %d", &n, &m, &q);

    static long long a[MAXN + 1], b[MAXN + 1];
    for (int i = 1; i <= n; i++) scanf("%lld", &a[i]);
    for (int i = 1; i <= m; i++) scanf("%lld", &b[i]);

    static long long zero[MAXN + 1], pa[MAXN + 1], ma[MAXN + 1];
    for (int i = 1; i <= n; i++) {
        if (a[i] > 0) pa[i] = a[i], ma[i] = INT_MAX;
        if (a[i] < 0) ma[i] = -a[i], pa[i] = INT_MAX;
        zero[i] = zero[i - 1] + (a[i] == 0);
    }

    segMinA = SegTMin::build(1, n, a);
    segMaxA = SegTMax::build(1, n, a);
    segMinB = SegTMin::build(1, m, b);
    segMaxB = SegTMax::build(1, m, b);
    segMinPA = SegTMin::build(1, n, pa);
    segMinMA = SegTMin::build(1, n, ma);

    while (q--) {
        long long ans = 0;
        int l1, r1, l2, r2;
        scanf("%d %d %d %d", &l1, &r1, &l2, &r2);

        long long minA = segMinA->query(l1, r1);
        long long maxA = segMaxA->query(l1, r1);
        long long minB = segMinB->query(l2, r2);
        long long maxB = segMaxB->query(l2, r2);

        if (l1 == r1) {
            if (a[l1] > 0) ans = minB * a[l1];
            else ans = maxB * a[l1];
        } else if (l2 == r2) {
            if (b[l2] > 0) ans = maxA * b[l2];
            else ans = minA * b[l2];
        } else {
            if (minB * maxB > 0) {
                if (minB >= 0) {
                    if (maxA < 0) ans = maxA * maxB;
                    else ans = maxA * minB;
                } else {
                    if (minA < 0) ans = minA * maxB;
                    else ans = minA * minB;
                }
            } else if (minB * maxB == 0) {
                if (minB == 0) {
                    if (maxA < 0) ans = maxA * maxB;
                    else ans = 0;
                } else {
                    if (minA < 0) ans = 0;
                    else ans = minA * minB;
                }
            } else if (minB * maxB < 0) {
                if (zero[r1] - zero[l1 - 1] > 0) {
                    ans = 0;
                } else {
                    long long npa = segMinPA->query(l1, r1);
                    long long nma = segMinMA->query(l1, r1);
                    ans = std::max(npa * minB, -nma * maxB);
                }
            }
        }

        printf("%lld\n", ans);
    }

    return 0;
}