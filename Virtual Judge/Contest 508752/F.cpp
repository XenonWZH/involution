#include <cstdio>
#include <algorithm>

const int MAXN = 100000;

template <typename T>
struct Splay {
    struct Node {
        Node *lchild, *rchild, *parent, **root;
        T value;
        int size;
        bool reversed;
        bool bound;

        Node(Node *parent, Node **root, const T &value, bool bound = false) : parent(parent), lchild(nullptr), rchild(nullptr), root(root), value(value), size(1), reversed(false), bound(bound) {}

        ~Node() {
            if (lchild) {
                delete lchild;
            }

            if (rchild) {
                delete rchild;
            }
        }

        void maintain() {
            size = lsize() + rsize() + 1;
        }

        int lsize() {
            return lchild ? lchild->size : 0;
        }

        int rsize() {
            return rchild ? rchild->size : 0;
        }

        Node *&child(int x) {
            return !x ? lchild : rchild;
        }

        Node *grandparent() {
            return !parent ? nullptr : parent->parent;
        }

        int relation() {
            return this == parent->lchild ? 0 : 1;
        }

        Node *pushdown() {
            if (reversed) {
                std::swap(lchild, rchild);

                if (lchild) {
                    lchild->reversed ^= 1;
                }

                if (rchild) {
                    rchild->reversed ^= 1;
                }

                reversed = false;
            }

            return this;
        }

        void rotate() {
            parent->pushdown();
            pushdown();

            Node *old = parent;
            int x = relation();

            if (grandparent()) {
                grandparent()->child(old->relation()) = this;
            }
            parent = grandparent();

            old->child(x) = child(x ^ 1);
            if (child(x ^ 1)) {
                child(x ^ 1)->parent = old;
            }

            child(x ^ 1) = old;
            old->parent = this;

            old->maintain();
            maintain();

            if (!parent) {
                *root = this;
            }
        }

        Node *splay(Node **target = nullptr) {
            if (!target) {
                target = root;
            }

            while (this != *target) {
                parent->pushdown();

                if (parent == *target) {
                    rotate();
                } else if (relation() == parent->relation()) {
                    parent->rotate();
                    rotate();
                } else {
                    rotate();
                    rotate();
                }
            }

            return *target;
        }
    } *root;

    ~Splay() {
        delete root;
    }

    void build(const T *a, int n) {
        root = build(a, 1, n, nullptr);

        Node **lbound = &root, *lbound_parent = nullptr;
        while (*lbound) {
            lbound_parent = *lbound;
            lbound_parent->size++;
            lbound = &(*lbound)->lchild;
        }
        *lbound = new Node(lbound_parent, &root, 0, true);

        Node **rbound = &root, *rbound_parent = nullptr;
        while (*rbound) {
            rbound_parent = *rbound;
            rbound_parent->size++;
            rbound = &(*rbound)->rchild;
        }
        *rbound = new Node(rbound_parent, &root, 0, true);
    }

    Node *build(const T *a, int l, int r, Node *parent) {
        if (l > r) {
            return nullptr;
        }

        int mid = l + (r - l) / 2;

        Node *node = new Node(parent, &root, a[mid - 1]);
        if (l != r) {
            node->lchild = build(a, l, mid - 1, node);
            node->rchild = build(a, mid + 1, r, node);
            node->maintain();
        }

        return node;
    }

    Node *select(int k) {
        k++;
        Node *node = root;
        while (k != node->pushdown()->lsize() + 1) {
            if (k < node->lsize() + 1) {
                node = node->lchild;
            } else {
                k -= node->lsize() + 1;
                node = node->rchild;
            }
        }

        return node->splay();
    }

    Node *select(int l, int r) {
        Node *lbound = select(l - 1);
        Node *rbound = select(r + 1);

        lbound->splay();
        rbound->splay(&lbound->rchild);

        return rbound->lchild;
    }

    void reverse(int l, int r) {
        Node *range = select(l, r);
        range->reversed ^= 1;
    }

    void fetch(T *a) {
        dfs(a, root);
    }

    void dfs(T* &a, Node *node) {
        if (node) {
            node->pushdown();

            dfs(a, node->lchild);

            if (!node->bound) {
                *a++ = node->value;
            }

            dfs(a, node->rchild);
        }
    }
};

void dfs(Splay<int>::Node *node, int depth = 0) {
    if (node) {
        dfs(node->rchild, depth + 1);

        for (int i = 0; i < depth; i++) {
            putchar(' ');
        }
        printf("%d : %u\n", node->value, node->size);

        dfs(node->lchild, depth + 1);
    }
}

int n, m;
Splay<int> splay;
int a[MAXN];

int main() {
    scanf("%u %u", &n, &m);

    for (int i = 0; i < n; i++) {
        a[i] = i + 1;
    }

    splay.build(a, n);

    for (int i = 0; i < m; i++) {
        int l, r;
        scanf("%u %u", &l, &r);
        splay.reverse(l, r);
    }

    splay.fetch(a);

    for (int i = 0; i < n; i++) {
        printf("%u ", a[i]);
    }
    putchar('\n');

    return 0;
}