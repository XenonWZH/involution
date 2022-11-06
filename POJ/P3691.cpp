#include <cstdio>
#include <cstring>
#include <climits>
#include <vector>
#include <queue>
#include <new>

const int MAXN = 1000;
const int CHARSET_SIZE = 4;

inline int get(const char c) {
    if (c == 'A') return 0;
    else if (c == 'G') return 1;
    else if (c == 'C') return 2;
    else return 3;
}

struct Trie {
    struct Node {
        int id;
        Node *c[CHARSET_SIZE], *next, *fail;
        bool isWord;

        Node(bool isWord = false) : next(NULL), fail(NULL), isWord(isWord) { 
            for (int i = 0; i < CHARSET_SIZE; i++) c[i] = NULL;
        }

        Node(int id, bool isWord = false) : id(id), next(NULL), fail(NULL), isWord(isWord) {
            for (int i = 0; i < CHARSET_SIZE; i++) c[i] = NULL;
        }
    } *root, _pool[MAXN + 1], *_curr;

    int idx;

    Trie() : root(_pool), _curr(_pool + 1), idx(0) { root->id = 0; }

    Node *insert(const char *begin, const char *end) {
        Node **v = &root;
        for (const char *p = begin; p != end; p++) {
            if (!*v) *v = new (_curr++) Node(++idx);
            v = &(*v)->c[get(*p)];
        }
        if (!*v) *v = new (_curr++) Node(++idx);
        (*v)->isWord = true;
        return *v;
    }

    void build() {
        std::queue<Node *> q;
        q.push(root);
        root->fail = root;
        root->next = NULL;
        while (!q.empty()) {
            Node *v = q.front();
            q.pop();

            for (int i = 0; i < CHARSET_SIZE; i++) {
                Node *&c = v->c[i];

                if (!c) {
                    c = v == root ? root : v->fail->c[i];
                    continue;
                }
                Node *u = v->fail;

                c->fail = v != root && u->c[i] ? u->c[i] : root;

                c->next = c->fail->isWord ? c->fail : c->fail->next;
                q.push(c);

                c->isWord |= c->fail->isWord;
            }
        }
    }
};

int main() {
    int n, counts = 0;

    while (scanf("%d", &n) != EOF && n) {
        static char s[MAXN + 1];
        Trie t;
        std::vector<Trie::Node *> node(n);
        for (int i = 0; i < n; i++) {
            scanf("%s", s);
            node[i] = t.insert(s, s + strlen(s));
        }

        t.build();

        scanf("%s", s);
        int m = strlen(s);

        std::vector< std::vector<int> > f(m + 1, std::vector<int>(t.idx + 1, INT_MAX));
        f[0][0] = 0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j <= t.idx; j++) {
                if (f[i][j] != INT_MAX) {
                    for (int k = 0; k < CHARSET_SIZE; k++) {
                        int l = get(s[i]) != k;
                        Trie::Node *p = t._pool[j].c[k];
                        if (!p->isWord) f[i + 1][p->id] = std::min(f[i + 1][p->id], f[i][j] + l);
                    }
                }
            }
        }

        int ans = INT_MAX;
        for (int i = 0; i <= t.idx; i++) ans = std::min(ans, f[m][i]);

        printf("Case %d: %d\n", ++counts, ans == INT_MAX ? -1 : ans);
    }

    return 0;
}