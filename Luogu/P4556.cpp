#include <cstdio>
#include <iostream>
#include <vector>

const int MAXN = 1e5;
const int LOG_MAXN = 17;

struct Food {
    int cnt, type;

    Food() {}
    Food(int cnt, int type) : cnt(cnt), type(type) {}

    bool operator>(const Food &other) {
        if (cnt == other.cnt) return type < other.type;
        return cnt > other.cnt;
    }
};

struct SegT {
    int l, r;
    SegT *lc, *rc;
    Food val;

    SegT(int l, int r, SegT *lc, SegT *rc) : l(l), r(r), lc(lc), rc(rc), val(Food(0, 0)) {}
    SegT(int l, int r, SegT *lc, SegT *rc, Food val) : l(l), r(r), lc(lc), rc(rc), val(val) {}

    static SegT *build(const int l, const int r) {
        if (l > r) return NULL;
        else if (l == r) return new SegT(l, r, NULL, NULL, Food(0, l));
        else return new SegT(l, r, NULL, NULL);
    }

    void update(const int pos, const long long delta) {
        if (pos > this->r || pos < this->l) return;
        else if (pos == this->l && pos == this->r) val.cnt += delta;
        else {
            int mid = l + (r - l) / 2;
            if (pos <= mid) {
                if (!lc) lc = build(l, mid);
                lc->update(pos, delta);
            } else {
                if (!rc) rc = build(mid + 1, r);
                rc->update(pos, delta);
            }
            Food res(0, 0);
            if (lc && lc->val > res) res = lc->val;
            if (rc && rc->val > res) res = rc->val;
            val = res;
        }
    }

    static SegT *merge(SegT *u, SegT *v) {
        if (!u) return v;
        if (!v) return u;
        if (u->l == u->r) {
            u->val.cnt = u->val.cnt + v->val.cnt;
            return u;
        }

        u->lc = merge(u->lc, v->lc);
        u->rc = merge(u->rc, v->rc);
        Food res(0, 0);
        if (u->lc && u->lc->val > res) res = u->lc->val;
        if (u->rc && u->rc->val > res) res = u->rc->val;
        u->val = res;

        return u;
    }
};

struct Node {
    std::vector<struct Edge> e;
    int d, ans;
    Node *p, *f[LOG_MAXN + 1];
    SegT *segment;
} N[MAXN + 1];

struct Edge {
    Node *s, *t;

    Edge(Node *s, Node *t) : s(s), t(t) {}
};

int n, m;
int ans[MAXN + 1];

inline void addEdge(int s, int t) {
    N[s].e.push_back(Edge(&N[s], &N[t]));
    N[t].e.push_back(Edge(&N[t], &N[s]));
}

void prepare(Node *v, Node *f = NULL) {
    v->f[0] = v->p = f;
    v->d = (f ? f->d : 0) + 1;
    for (int i = 1; i <= LOG_MAXN; i++) {
        if (v->f[i - 1]) {
            v->f[i] = v->f[i - 1]->f[i - 1];
        }
    }
    for (Edge *e = &v->e.front(); e && e <= &v->e.back(); e++) {
        if (e->t == f) continue;
        prepare(e->t, v);
    }
}

inline Node *lca(Node *u, Node *v) {
    if (u->d < v->d) std::swap(u, v);
    if (u->d != v->d) {
        for (int i = LOG_MAXN; i >= 0; i--) {
            if (u->f[i] && u->f[i]->d >= v->d) {
                u = u->f[i];
            }
        }
    }
    if (u != v) {
        for (int i = LOG_MAXN; i >= 0; i--) {
            if (u->f[i] != v->f[i]) {
                u = u->f[i];
                v = v->f[i];
            }
        }
        return u->p;
    }
    return u;
}

void dfs(Node *v, Node *f = NULL) {
    for (Edge *e = &v->e.front(); e && e <= &v->e.back(); e++) {
        if (e->t == f) continue;
        dfs(e->t, v);
    }
    v->ans = v->segment->val.type;
    if (f) f->segment = SegT::merge(f->segment, v->segment);
}

int main() {
    scanf("%d %d", &n, &m);
    for (int i = 1; i <= n - 1; i++) {
        int a, b;
        scanf("%d %d", &a, &b);
        addEdge(a, b);
    }

    for (int i = 1; i <= n; i++) N[i].segment = SegT::build(1, MAXN);
    prepare(&N[1]);
    while (m--) {
        int x, y, z;
        scanf("%d %d %d", &x, &y, &z);
        Node *u = &N[x], *v = &N[y];
        Node *f = lca(u, v);
        u->segment->update(z, 1);
        v->segment->update(z, 1);
        f->segment->update(z, -1);
        if (f->p) f->p->segment->update(z, -1);
    }

    dfs(&N[1]);

    for (int i = 1; i <= n; i++) printf("%d\n", N[i].ans);

    return 0;
}