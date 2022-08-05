#include <cstdio>
#include <algorithm>

const int MAXN = 100000;

template <typename T>
struct Splay {
    enum Relation {
        L = 0, R = 1
    };

    struct Node {
        Node *c[2], *p, **r;
        T v;
        int s;
        bool b;

        Node(Node *p, Node **r, const T &v, bool b = false) : p(p), r(r), v(v), s(1), b(b) {}

        ~Node() {
            if (c[L]) delete c[L];
            if (c[R]) delete c[R];
        }

        Relation relation() const {
            return this == p->c[L] ? L : R;
        }

        void maintain() {
            s = (c[L] ? c[L]->s : 0) + (c[R] ? c[R]->s : 0) + 1;
        }

        void rotate() {
            Relation x = relation();
            Node *o = p;

            if (o->p) o->p->c[o->relation()] = this;
            p = o->p;

            o->c[x] = c[x ^ 1];
            if (c[x ^ 1]) c[x ^ 1]->p = o;

            c[x ^ 1] = o;
            o->p = this;

            o->maintain(), maintain();
            if (!p) *r = this;
        }

        void splay(const Node *t = nullptr) {
            while (p != t) {
                if (p->p == t) rotate();
                else if (p->relation() == relation()) p->rotate(), rotate();
                else rotate(), rotate();
            }
        }

        int rank() {
            return c[L] ? c[L]->s : 0;
        }
    } *r;

    Splay() : r(nullptr) {
        buildBound(L), buildBound(R);
    }

    ~Splay() {
        delete r;
    }

    void buildBound(Relation x) {
        Node **v = &r, *p = nullptr;
        while (*v) p = *v, p->s++, v = &p->c[x];
        *v = new Node(p, &r, 0, true);
    }

    Node *select(int k) {
        Node *v = r;
        for (int x = k + 1; x != v->rank() + 1; ) {
            if (x < v->rank() + 1) v = v->c[L];
            else x -= v->rank() + 1, v = v->c[R];
        }
        return v;
    }

    void insert(int i, const T &v) {
        Node *a = select(i), *b = select(i + 1);
        a->splay(), b->splay(a);
        b->c[L] = new Node(b, &r, v), b->s++, b->s++;
    }

    void dfs(Node *v, T *a, int &i) {
        if (!v) return;
        dfs(v->c[L], a, i), v->b || (a[v->v - 1] = ++i), dfs(v->c[R], a, i);
    }

    void fetch(T *a) {
        int i = 0;
        dfs(r, a, i);
    }
};

int n, a[MAXN];

struct BinaryIndexedTree {
    int a[MAXN];

    static int lowbit(const int x) {
        return x & -x;
    }

    void update(const int i, const int v) {
        for (int j = i; j <= n; j += lowbit(j)) a[j - 1] = std::max(a[j - 1], v);
    }

    int query(const int i) {
        int x = 0;
        for (int j = i; j > 0; j -= lowbit(j)) x = std::max(x, a[j - 1]);
        return x;
    }
} b;

Splay<int> s;

int main() {
    scanf("%d", &n);
    for (int x = 1, i; x <= n; x++) {
        scanf("%d", &i);
        s.insert(i, x);
    }

    s.fetch(a);

    for (int i = 0, l = 0; i < n; i++) {
        int t = b.query(a[i] - 1) + 1;
        b.update(a[i], t);
        printf("%d\n", l = std::max(l, t));
    }

    return 0;
}