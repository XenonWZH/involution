#include <cstdio>
#include <climits>

struct Splay {
    struct Node {
        Node *fa, *ch[2], **root;
        int x, size, cnt;

        Node (Node **root, Node *fa, int x) : root(root), fa(fa), x(x), cnt(1), size(1) {
            ch[0] = ch[1] = nullptr;
        }

        int relation() {
            return this == fa->ch[0] ? 0 : 1;
        }

        void maintain() {
            size = cnt;
            if (ch[0]) size += ch[0]->size;
            if (ch[1]) size += ch[1]->size;
        }

        void rotate() {
            Node *old = fa;
            int r = relation();

            fa = old->fa;
            if (old->fa) {
                old->fa->ch[old->relation()] = this;
            }

            if (ch[r ^ 1]) {
                ch[r ^ 1]->fa = old;
            }
            old->ch[r] = ch[r ^ 1];

            old->fa = this;
            ch[r ^ 1] = old;

            old->maintain();
            maintain();

            if (fa == nullptr) {
                *root = this;
            }
        }

        void splay(Node *target = nullptr) {
            while (fa != target) {
                if (fa->fa == target) {
                    rotate();
                } else if (fa->relation() == relation()) {
                    fa->rotate();
                    rotate();
                } else {
                    rotate();
                    rotate();
                }
            }
        }

        Node *pred() {
            Node *v = ch[0];
            while (v->ch[1]) v = v->ch[1];
            return v;
        }

        Node *succ() {
            Node *v = ch[1];
            while (v->ch[0]) v = v->ch[0];
            return v;
        }

        int rank() {
            return ch[0] ? ch[0]->size : 0;
        }
    } *root;

    Splay() : root(nullptr) {
        insert(INT_MIN);
        insert(INT_MAX);
    }

    Node *insert(int x) {
        Node **v = &root, *fa = nullptr;
        while (*v != nullptr && (*v)->x != x) {
            fa = *v;
            fa->size++;

            if (x < fa->x) {
                v = &fa->ch[0];
            } else {
                v = &fa->ch[1];
            }
        }

        if (*v != nullptr) {
            (*v)->cnt++;
            (*v)->size++;
        } else {
            (*v) = new Node(&root, fa, x);
        }

        (*v)->splay();

        return root;
    }

    Node *find(int x) {
        Node *v = root;
        while (v != nullptr && v->x != x) {
            if (x < v->x) {
                v = v->ch[0];
            } else {
                v = v->ch[1];
            }
        }

        if (v) v->splay();
        return v;
    }

    void erase(Node *v) {
        Node *pred = v->pred(), *succ = v->succ();
        pred->splay();
        succ->splay(pred);

        if (v->size > 1) {
            v->size--;
            v->cnt--;
        } else {
            delete succ->ch[0];
            succ->ch[0] = nullptr;
        }

        succ->size--;
        pred->size--;
    }

    void erase(int x) {
        Node *v = find(x);
        if (!v) return;

        erase(v);
    }

    int pred(int x) {
        Node *v = find(x);
        if (v == nullptr) {
            v = insert(x);
            int res = v->pred()->x;
            erase(v);
            return res;
        } else {
            return v->pred()->x;
        }
    }

    int succ(int x) {
        Node *v = find(x);
        if (v == nullptr) {
            v = insert(x);
            int res = v->succ()->x;
            erase(v);
            return res;
        } else {
            return v->succ()->x;
        }
    }

    int rank(int x) {
        Node *v = find(x);
        if (v == nullptr) {
            v = insert(x);

            int res = v->rank();
            erase(v);
            return res;
        } else {
            return v->rank();
        }
    }

    int select(int k) {
        Node *v = root;
        while (!(k >= v->rank() && k < v->rank() + v->cnt)) {
            if (k < v->rank()) {
                v = v->ch[0];
            } else {
                k -= v->rank() + v->cnt;
                v = v->ch[1];
            }
        }
        v->splay();
        return v->x;
    }
} splay;

int main() {
    int n;
    scanf("%d", &n);
    while (n--) {
        int opt, x;
        scanf("%d %d", &opt, &x);
        if (opt == 1) {
            splay.insert(x);
        } else if (opt == 2) {
            splay.erase(x);
        } else if (opt == 3) {
            printf("%d\n", splay.rank(x));
        } else if (opt == 4) {
            printf("%d\n", splay.select(x));
        } else if (opt == 5) {
            printf("%d\n", splay.pred(x));
        } else if (opt == 6) {
            printf("%d\n", splay.succ(x));
        }
    }
    return 0;
}