#include <cstdio>
#include <algorithm>
#include <map>

const int MAXN = 100000;

struct Point {
    long long x, y, z;
    int k;

    inline bool operator < (const Point &o) const {
        return this->x < o.x;
    }
} a[2 * MAXN + 1];

int n, m;
long long raw[2 * MAXN + 1];
std::map<long long, int> val;

struct SegmentTree {
    int l, r, cnt;
    long long len;
} t[2 * 4 * MAXN + 1];

void build(int p, int l, int r) {
    t[p].l = l, t[p].r = r, t[p].cnt = 0, t[p].len = 0;
    if (l == r) return;

    build((p << 1), l, ((t[p].l + t[p].r) >> 1));
    build(((p << 1) | 1), ((t[p].l + t[p].r) >> 1) + 1, r);
}

void change(int p, int l, int r, long long k) {
    if (l <= t[p].l && r >= t[p].r) {
        t[p].cnt += k;
        if (t[p].cnt > 0) t[p].len = raw[t[p].r+1] - raw[t[p].l];
        else if (t[p].l == t[p].r) t[p].len = 0;
        else t[p].len = t[(p << 1)].len + t[((p << 1) | 1)].len;

        return;
    }

    if (l <= ((t[p].l + t[p].r) >> 1)) change((p << 1), l, r, k);
    if (r > ((t[p].l + t[p].r) >> 1)) change(((p << 1) | 1), l, r, k);

    if (t[p].cnt > 0) t[p].len = raw[t[p].r+1] - raw[t[p].l];
    else t[p].len =  t[(p << 1)].len + t[((p << 1) | 1)].len;
}

int main() {
    scanf("%d", &n);

    for (int i = 1; i <= n; i++) {
        int k = i << 1;
        long long y, z;
        scanf("%lld %lld %lld %lld", &a[k-1].x, &y, &a[k].x, &z);
        raw[k-1] = a[k-1].y = a[k].y = y;
        raw[k] = a[k-1].z = a[k].z = z;
        a[k-1].k = 1, a[k].k = -1;
    }

    n <<= 1;
    std::sort(raw + 1, raw + n + 1);
    int m = std::unique(raw + 1, raw + n + 1) - (raw + 1);
    for (int i = 1; i <= m; i++) val[raw[i]] = i;
    std::sort(a + 1, a + n + 1);

    build(1, 1, m - 1);

    long long ans = 0;

    for (int i = 1; i < n; i++) {
        int y = val[a[i].y], z = val[a[i].z] - 1;
        change(1, y, z, a[i].k);
        ans += t[1].len * (a[i+1].x - a[i].x);
    }

    printf("%lld\n", ans);

    return 0;
}