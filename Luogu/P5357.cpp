#include <cstdio>
#include <cstring>
#include <queue>

const int MAXN = 2e5;
const int MAXS = 2e6;
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
    } *root;

    Trie() : root(new Node()) {}

    Node *insert(const char *begin, const char *end) {
        Node **v = &root;
        for (const char *p = begin; p != end; p++) {
            if (!*v) *v = new Node;
            v = &(*v)->c[*p - BASE_CHAR];
        }
        if (!*v) *v = new Node(true);
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
} t;

int main() {
    int n;
    scanf("%d", &n);

    static char str[MAXN + 1];
    static Trie::Node *node[MAXN];
    for (int i = 0; i < n; i++) {
        scanf("%s", str);
        node[i] = t.insert(str, str + strlen(str));
    }

    t.build();

    static char s[MAXS + 1];
    scanf("%s", s);
    t.exec(s, s + strlen(s));

    for (int i = 0; i < n; i++) printf("%d\n", node[i]->ans);

    return 0;
}