#include <iostream>

const int MAXN = 50000, INF = 0x3f3f3f3f;

struct SegmentTree {
    int l, r;
    int dat, sum, lmax, rmax;
} t[MAXN * 4];

int a[MAXN + 1], n, q;

void build(int p, int l, int r) {
    t[p].l = l, t[p].r = r;
    if (l == r) {
        t[p].sum = t[p].lmax = t[p].rmax = t[p].dat = a[l];
        return;
    }
    int mid = (l + r) / 2;
    build(p * 2, l, mid);
    build(p * 2 + 1, mid + 1, r);
    t[p].sum = t[p * 2].sum + t[p * 2 + 1].sum;
    t[p].lmax = std::max(t[p * 2].lmax, t[p * 2].sum + t[p * 2 + 1].lmax);
    t[p].rmax = std::max(t[p * 2 + 1].rmax, t[p * 2 + 1].sum + t[p * 2].rmax);
    t[p].dat = std::max(std::max(t[p * 2].dat, t[p * 2 + 1].dat), t[p * 2].rmax + t[p * 2 + 1].lmax);
}

void change(int p, int x, int v) {
    if (t[p].l == t[p].r) {
        t[p].sum = t[p].lmax = t[p].rmax = t[p].dat = v;
        return;
    }
    int mid = (t[p].l + t[p].r) / 2;
    if (x <= mid) change(p * 2, x, v);
    else change(p * 2 + 1, x, v);
    t[p].sum = t[p * 2].sum + t[p * 2 + 1].sum;
    t[p].lmax = std::max(t[p * 2].lmax, t[p * 2].sum + t[p * 2 + 1].lmax);
    t[p].rmax = std::max(t[p * 2 + 1].rmax, t[p * 2 + 1].sum + t[p * 2].rmax);
    t[p].dat = std::max(std::max(t[p * 2].dat, t[p * 2 + 1].dat), t[p * 2].rmax + t[p * 2 + 1].lmax);
}

SegmentTree ask(int p, int l, int r) {
    if (l <= t[p].l && r >= t[p].r) return t[p];
    SegmentTree a, b, ans;
    a.sum = a.lmax = a.rmax = a.dat = -INF;
    b.sum = b.lmax = b.rmax = b.dat = -INF;
    ans.sum = 0;
    int mid = (t[p].l + t[p].r) / 2;
    if (l <= mid) {
        a = ask(p * 2, l, r);
        ans.sum += a.sum;
    }
    if (r > mid) {
        b = ask(p * 2 + 1, l, r);
        ans.sum += b.sum;
    }
    ans.dat = std::max(std::max(a.dat, b.dat), a.rmax + b.lmax);
	ans.lmax = std::max(a.lmax, a.sum + b.lmax);
	ans.rmax = std::max(b.rmax, b.sum + a.rmax);
	if (l > mid) ans.lmax = std::max(ans.lmax, b.lmax);
	if (r <= mid) ans.rmax = std::max(ans.rmax, a.rmax);
	return ans;
}

int main() {
    std::cin >> n;
    for (int i = 1; i <= n; i++) {
        scanf("%d", &a[i]);
    }

    build(1, 1, n);

    std::cin >> q;
    for (int i = 1, op, x, y; i <= q; i++) {
        scanf("%d%d%d", &op, &x, &y);
        if (op == 0) change(1, x, y);
        else {
            if (x > y) std::swap(x, y);
            printf("%d\n", ask(1, x, y).dat);
        }
    }

    return 0;
}