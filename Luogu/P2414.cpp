#include <cstdio>
#include <queue>
#include <stack>
#include <algorithm>

const int MAXN = 1e5;
const int CHARSET_SIZE = 'z' - 'a' + 1;
const int BASE_CHAR = 'a';

struct Trie {
    struct Node {
        Node *c[CHARSET_SIZE], *fail, *next, *p;
        int id;
        bool isWord;
        struct Get {
            Node *x;
            int *ans;

            Get(Node *x, int *ans) : x(x), ans(ans) {}
        };
        std::vector<Get> q;

        Node(Node *p, bool isWord, const int id) : fail(nullptr), next(nullptr), p(p), id(id), isWord(isWord) {
            for (int i = 0; i < CHARSET_SIZE; i++) c[i] = nullptr;
        }
    } *root;

    Trie() : root(nullptr) {}

    int init(const char *s, std::vector<Node *> &vec) {
        int cnt = 0;
        Node *v = root = new Node(nullptr, false, cnt++);
        for (const char *p = s; *p; p++) {
            if (*p == 'P') {
                v->isWord = true;
                vec.push_back(v);
            } else if (*p == 'B') v = v->p;
            else {
                if (!v->c[*p - BASE_CHAR]) v->c[*p - BASE_CHAR] = new Node(v, false, cnt++);
                v = v->c[*p - BASE_CHAR];
            }
        }
        return cnt;
    }

    void build() {
        std::queue<Node *> q;
        root->fail = root;
        root->next = nullptr;
        q.push(root);
        while (!q.empty()) {
            Node *v = q.front();
            q.pop();

            for (int i = 0; i < CHARSET_SIZE; i++) {
                Node *&c = v->c[i];
                if (!c) continue;
                Node *u = v->fail;
                while (u != root && !u->c[i]) u = u->fail;
                c->fail = v != root && u->c[i] ? u->c[i] : root;
                c->next = c->fail->isWord ? c->fail : c->fail->next;
                q.push(c);
            }
        }
    }
} t;

struct BinaryIndexedTree {
    int a[MAXN + 1], n;

    void init(const int n) {
        this->n = n;
    }

    static int lowbit(const int x) {
        return x & -x;
    }

    void update(const int pos, const int delta) {
        for (int i = pos; i <= n; i += lowbit(i)) a[i] += delta;
    }

    int query(const int pos) {
        int ans = 0;
        for (int i = pos; i > 0; i -= lowbit(i)) ans += a[i];
        return ans;
    }
} bit;

struct Node {
    Node *p, *c, *next;
    int l, r;
    bool v;
} N[MAXN];

int n;
char op[MAXN + 1];

inline void addEdge(const int p, const int c) {
    N[c].next = N[p].c;
    N[p].c = &N[c];
    N[c].p = &N[p];
}

inline void buildFailTree() {
    std::queue<Trie::Node *> q;
    q.push(t.root);

    while (!q.empty()) {
        Trie::Node *v = q.front();
        q.pop();

        for (int i = 0; i < CHARSET_SIZE; i++) {
            Trie::Node *&c = v->c[i];
            if (!c) continue;
            addEdge(c->fail->id, c->id);
            q.push(c);
        }
    }
}

inline void dfs() {
    std::stack<Node *> s;
    s.push(&N[0]);

    int ts = 0;
    while (!s.empty()) {
        Node *v = s.top();
        if (!v->v) {
            v->v = true;
            v->l = ++ts;
            for (Node *c = v->c; c; c = c->next) s.push(c);
        } else {
            v->r = ts;
            s.pop();
        }
    }
}

inline void solve() {
    bit.init(n);
    Trie::Node *y = t.root;
    for (const char *p = op; *p; p++) {
        if (*p == 'P') {
            for (auto it = y->q.begin(); it != y->q.end(); it++) {
                *it->ans = bit.query(N[it->x->id].r) - bit.query(N[it->x->id].l - 1);
            }
        } else if (*p == 'B') {
            bit.update(N[y->id].l, -1);
            y = y->p;
        } else {
            y = y->c[*p - BASE_CHAR];
            bit.update(N[y->id].l, 1);
        }
    }
}

int main() {
    scanf("%s", op);

    std::vector<Trie::Node *> vec;
    n = t.init(op, vec);
    t.build();

    buildFailTree();
    dfs();

    int m;
    static int ans[MAXN];
    scanf("%d", &m);
    for (int i = 0; i < m; i++) {
        int x, y;
        scanf("%d %d", &x, &y);
        vec[y - 1]->q.push_back(Trie::Node::Get(vec[x - 1], &ans[i]));
    }

    solve();

    for (int i = 0; i < m; i++) {
        printf("%d\n", ans[i]);
    }

    return 0;
}