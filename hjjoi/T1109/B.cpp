#include <cstdio>
#include <algorithm>
#include <map>

const int MAXN = 100000;

int n;
double raw[2 * MAXN + 1];
std::map<double, int> val;

struct Point {
    double x, y, z;
    int k;

    static bool comp(Point a, Point b) { return a.x < b.x; }
} a[2 * MAXN + 1];

struct SegT {
    int l, r;
    SegT *lc, *rc;
    int cnt;
    double len;

    SegT(int l, int r, SegT *lc, SegT *rc) : l(l), r(r), lc(lc), rc(rc), cnt(0), len(0) {}

    void update(const int l, const int r, const double delta) {
        if (l <= this->l && r >= this->r) {
            this->cnt += delta;
            if (this->cnt > 0) {
                this->len = raw[this->r + 1] - raw[this->l];
            } else {
                if (this->l == this->r) this->len = 0;
                else this->len = lc->len + rc->len;
            }
        } else {
            const int mid = (this->l + this->r) / 2;
            if (l <= mid) lc->update(l, r, delta);
            if (r > mid) rc->update(l, r, delta);

            if (cnt > 0) this->len = raw[this->r + 1] - raw[this->l];
            else this->len = lc->len + rc->len;
        }
    }

    static SegT *build(const int l, const int r) {
        if (l > r) return NULL;
        else if (l == r) return new SegT(l, r, NULL, NULL);
        else {
            const int mid = l + (r - l) / 2;
            return new SegT(l, r, build(l, mid), build(mid + 1, r));
        }
    }
} *segment;

int main() {
    int counts = 0;

    while (scanf("%d", &n) != EOF && n != 0) {
        for (int i = 1; i <= n; i++) {
            scanf("%lf %lf %lf %lf", &a[2 * i - 1].x, &a[2 * i].y, &a[2 * i].x, &a[2 * i].z);
            raw[2 * i - 1] = a[2 * i - 1].y = a[2 * i].y;
            raw[2 * i] = a[2 * i - 1].z = a[2 * i].z;
            a[2 * i - 1].k = 1;
            a[2 * i].k = -1;
        }

        std::sort(raw + 1, raw + 2 * n + 1);
        int m = std::unique(raw + 1, raw + 2 * n + 1) - (raw + 1);
        for (int i = 1; i <= m; i++) val[raw[i]] = i;
        std::sort(a + 1, a + 2 * n + 1, Point::comp);

        segment = SegT::build(1, m - 1);
        double ans = 0;

        for (int i = 1; i < 2 * n; i++) {
            int y = val[a[i].y], z = val[a[i].z] - 1;
            segment->update(y, z, a[i].k);
            ans += segment->len * (a[i + 1].x - a[i].x);
        }

        printf("Test case #%d\nTotal explored area: %.2f\n\n", ++counts, ans);
    }

    return 0;
}