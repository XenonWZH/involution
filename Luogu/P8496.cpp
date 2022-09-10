#include <cstdio>
#include <iostream>
#include <list>

const int MAXN = 5e5;

struct SegT {
    int l, r;
    SegT *lc, *rc;
    std::pair<long long, int> val;

    SegT(int l, int r, SegT *lc, SegT *rc) : l(l), r(r), lc(lc), rc(rc), val(std::make_pair(0, 0)) {}
    SegT(int l, int r, SegT *lc, SegT *rc, std::pair<long long, int> val) : l(l), r(r), lc(lc), rc(rc), val(val) {}

    static SegT *build(const int l, const int r) {
        if (l > r) return NULL;
        else if (l == r) return new SegT(l, r, NULL, NULL, std::make_pair(0, l));
        else return new SegT(l, r, NULL, NULL);
    }

    void update(const int pos, const long long delta) {
        if (pos > this->r || pos < this->l) return;
        else if (pos == this->l && pos == this->r) val.first += delta;
        else {
            int mid = l + (r - l) / 2;
            if (pos <= mid) {
                if (!lc) lc = build(l, mid);
                lc->update(pos, delta);
            } else {
                if (!rc) rc = build(mid + 1, r);
                rc->update(pos, delta);
            }
            std::pair<long long, int> res = std::make_pair(0, 0);
            if (lc) res = std::max(res, lc->val);
            if (rc) res = std::max(res, rc->val);
            val = res;
        }
    }

    std::pair<long long, int> query(const int pos) {
        if (pos > this->r || pos < this->l) return std::make_pair(0, 0);
        else if (this->l == this->r) return val;
        else {
            std::pair<long long, int> res = std::make_pair(0, 0);
            if (lc) res = std::max(res, lc->query(pos));
            if (rc) res = std::max(res, rc->query(pos));
            return res;
        }
    }

    static SegT *merge(SegT *u, SegT *v) {
        if (!u) return v;
        if (!v) return u;
        SegT *w = build(u->l, u->r);
        if (w->l == w->r) {
            w->val.first = u->val.first + v->val.first;
            return w;
        }

        w->lc = merge(u->lc, v->lc);
        w->rc = merge(u->rc, v->rc);
        std::pair<long long, int> res = std::make_pair(0, 0);
        if (w->lc) res = std::max(res, w->lc->val);
        if (w->rc) res = std::max(res, w->rc->val);
        w->val = res;

        return w;
    }
} *segment[2 * MAXN + 1];

int n, q;
long long l[2 * MAXN + 1];
std::list<int> a[2 * MAXN + 1];

inline int read() {
    int x = 0, w = 1;
    char ch = 0;
    while (ch < '0' || ch > '9') {
        if (ch == '-') w = -1;
        ch = getchar();
    }
    while (ch >= '0' && ch <= '9') {
        x = x * 10 + (ch - '0');
        ch = getchar();
    }
    return x * w;
}

int main() {
    n = read(), q = read();
    for (int i = 1; i <= n; i++) {
        segment[i] = SegT::build(1, 2 * MAXN);
        l[i] = read();
        for (int j = 1; j <= l[i]; j++) {
            int x;
            x = read();
            segment[i]->update(x, 1);
            a[i].push_back(x);
        }
    }

    while (q--) {
        int cmd;
        cmd = read();

        if (cmd == 1) {
            int x, y;
            x = read(), y = read();
            segment[x]->update(y, 1);
            a[x].push_back(y);
            l[x]++;
        } else if (cmd == 2) {
            int x;
            x = read();
            segment[x]->update(a[x].back(), -1);
            a[x].pop_back();
            l[x]--;
        } else if (cmd == 3) {
            int m;
            static int x[MAXN + 1];
            m = read();
            for (int i = 1; i <= m; i++) x[i] = read();

            std::pair<long long, int> res = std::make_pair(0, 0);
            for (int i = 1; i <= m; i++) {
                if (2 * segment[x[i]]->val.first <= l[x[i]]) continue;
                std::pair<long long, int> now = std::make_pair(segment[x[i]]->val.first - (l[x[i]] - segment[x[i]]->val.first), segment[x[i]]->val.second);
                if (now.second == res.second) res.first += now.first;
                else if (now.first == res.first) res = std::make_pair(0, 0);
                else if (now.first > res.first) res = std::make_pair(now.first - res.first, now.second);
                else if (now.first < res.first) res.first -= now.first;
            }

            if (res.first == 0) puts("-1");
            else {
                long long cnt = 0, len = 0;
                for (int i = 1; i <= m; i++) {
                    cnt += segment[x[i]]->query(res.second).first;
                    len += l[x[i]];
                }
                printf("%d\n", 2 * cnt > len ? res.second : -1);
            }
        } else if (cmd == 4) {
            int x1, x2, x3;
            x1 = read(), x2 = read(), x3 = read();

            segment[x3] = SegT::build(1, 2 * MAXN);
            segment[x3] = SegT::merge(segment[x3], segment[x1]);
            segment[x3] = SegT::merge(segment[x3], segment[x2]);
            a[x3].splice(a[x3].end(), a[x1]);
            a[x3].splice(a[x3].end(), a[x2]);
            l[x3] = l[x1] + l[x2];
        }
    }

    return 0;
}