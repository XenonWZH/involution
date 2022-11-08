#include <cstdio>
#include <climits>

template <typename T, T INF>
struct Splay {
    enum Relation {
        L = 0, R = 1
    };

    struct Node {
        Node *child[2], *parent;
        T value;
        Node **root;
        int size, count;

        Node(Node *parent, const T &value, Node **root) : parent(parent), value(value), root(root), count(1) {
            child[L] = child[R] = NULL;
        }

        ~Node() {
            if (child[L]) delete child[L];
            if (child[R]) delete child[R];
        }

        Relation relation() {
            return this == parent->child[L] ? L : R;
        }

        void maintain() {
            size = (child[L] ? child[L]->size : 0) + (child[R] ? child[R]->size : 0) + count;
        }

        void rotate() {
            Relation x = relation();
            Node *oldParent = parent;

            if (oldParent->parent) oldParent->parent->child[oldParent->relation()] = this;
            parent = oldParent->parent;

            oldParent->child[x] = child[x ^ 1];
            if (child[x ^ 1]) child[x ^ 1]->parent = oldParent;

            child[x ^ 1] = oldParent;
            oldParent->parent = this;

            oldParent->maintain(), maintain();

            if (!parent) *root = this;
        }

        void splay(Node *targetParent = NULL) {
            while (parent != targetParent) {
                if (parent->parent == targetParent) rotate();
                else if (parent->relation() == relation()) parent->rotate(), rotate();
                else rotate(), rotate();
            }
        }

        Node *pred() {
            splay();
            Node *v = child[L];
            while (v->child[R]) v = v->child[R];
            v->splay();
            return v;
        }

        Node *succ() {
            splay();
            Node *v = child[R];
            while (v->child[L]) v = v->child[L];
            v->splay();
            return v;
        }

        int rank() {
            return !child[L] ? 0 : child[L]->size;
        }
    } *root;

    Splay() : root(NULL) {
        insert(INF), insert(-INF);
    }

    ~Splay() {
        delete root;
    }

    Node *find(const T &value) {
        Node *v = root;
        while (v && value != v->value) {
            if (value < v->value) {
                v = v->child[L];
            } else {
                v = v->child[R];
            }
        }

        if (!v) return NULL;

        v->splay();
        return v;
    }

    Node *insert(const T &value) {
        Node *v = find(value);
        if (v) {
            v->count++, v->maintain();
            return v;
        }

        Node **target = &root, *parent = NULL;

        while (*target) {
            parent = *target;
            parent->size++;
            if (value < parent->value) {
                target = &parent->child[L];
            } else {
                target = &parent->child[R];
            }
        }

        *target = new Node(parent, value, &root);
        (*target)->splay();

        return root;
    }

    void erase(const T &value) {
        erase(find(value));
    }

    void erase(Node *v) {
        if (v->count != 1) {
            v->splay();
            v->count--;
            v->maintain();
            return;
        }

        Node *pred = v->pred();
        Node *succ = v->succ();

        pred->splay();
        succ->splay(pred);

        delete succ->child[L];
        succ->child[L] = NULL;

        succ->maintain(), pred->maintain();
    }

    int rank(const T &value) {
        Node *v = find(value);
        if (v) {
            v->splay();
            return v->rank();
        } else {
            v = insert(value);
            int ans = v->rank();
            erase(v);
            return ans;
        }
    }

    Node *select(int k) {
        k++;
        Node *v = root;
        while (!(v->rank() + 1 <= k && v->rank() + v->count >= k)) {
            if (k < v->rank() + 1) {
                v = v->child[L];
            } else {
                k -= v->rank() + v->count;
                v = v->child[R];
            }
        }
        v->splay();
        return v;
    }

    const T &pred(const T &value) {
        Node *v = find(value);
        if (v) return v->pred()->value;
        else {
            v = insert(value);
            const T &ans = v->pred()->value;
            erase(v);
            return ans;
        }
    }

    const T &succ(const T &value) {
        Node *v = find(value);
        if (v) return v->succ()->value;
        else {
            v = insert(value);
            const T &ans = v->succ()->value;
            erase(v);
            return ans;
        }
    }
};

int main() {
    int n, m;
    scanf("%d %d", &n, &m);

    Splay<int, INT_MAX> splay;
    for (int i = 0; i < n; i++) {
        int x;
        scanf("%d", &x);
        splay.insert(x);
    }

    int last = 0, ans = 0;
    while (m--) {
        int op, x;
        scanf("%d %d", &op, &x);
        x ^= last;
        if (op == 1) splay.insert(x);
        else if (op == 2) splay.erase(x);
        else if (op == 3) last = splay.rank(x);
        else if (op == 4) last = splay.select(x)->value;
        else if (op == 5) last = splay.pred(x);
        else if (op == 6) last = splay.succ(x);
        if (op >= 3 && op <= 6) ans ^= last;
    }

    printf("%d\n", ans);

    return 0;
}