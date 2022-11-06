#include <cstdio>
#include <cstring>
#include <iostream>
#include <queue>
#include <new>

const int MAXN = 150;
const int MAXT = 1e6;
const int CHARSET_SIZE = 'z' - 'a' + 1;
const int BASE_CHAR = 'a';

struct Trie {
    struct Node {
        Node *c[CHARSET_SIZE], *next, *fail;
        bool isWord;
        int ans;

        Node(bool isWord = false) : next(NULL), fail(NULL), isWord(isWord) {
            for (int i = 0; i < CHARSET_SIZE; i++) c[i] = NULL;
        }

        void apply() {
            ans++;
            if (next) next->apply();
        }
    } *root, _pool[2500 * MAXN + 1], *_curr;

    Trie() : root(_pool), _curr(_pool + 1) {}

    Node *insert(const char *begin, const char *end) {
        Node **v = &root;
        for (const char *p = begin; p != end; p++) {
            if (!*v) *v = new (++_curr) Node;
            v = &(*v)->c[*p - BASE_CHAR];
        }
        if (!*v) *v = new (++_curr) Node(true);
        else (*v)->isWord = true;
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
            }
        }
    }

    void exec(const char *begin, const char *end) {
        Node *v = root;
        for (const char *p = begin; p != end; p++) {
            v = v->c[*p - BASE_CHAR];

            if (v->isWord) v->apply();
            else if (v->next) v->next->apply();
        }
    }
} trie;

int main() {
    int n;

    while (scanf("%d", &n) != EOF) {
        if (n == 0) break;

        for (int i = 0; i <= n; i++) trie._pool[i] = Trie::Node();

        static char str[MAXN][MAXT + 1];
        static Trie::Node *node[MAXN];
        for (int i = 0; i < n; i++) {
            scanf("%s", str[i]);
            node[i] = trie.insert(str[i], str[i] + strlen(str[i]));
        }

        trie.build();

        static char t[MAXT + 1];
        scanf("%s", t);
        trie.exec(t, t + strlen(t));

        int ans = 0;
        for (int i = 0; i < n; i++) ans = std::max(ans, node[i]->ans);

        printf("%d\n", ans);
        for (int i = 0; i < n; i++) {
            if (node[i]->ans == ans) {
                printf("%s\n", str[i]);
            }
        }
    }

    return 0;
}