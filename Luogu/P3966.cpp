#include <cstdio>
#include <cstring>
#include <queue>

const int MAXN = 1e6 + 200;
const int CHARSET_SIZE = 'z' - '`' + 1;
const char BASE_CHAR = '`';

struct Trie {
    struct Node {
        Node *c[CHARSET_SIZE], *next, *fail;
        bool isWord;
        int ans;

        Node(const bool isWord = false) : next(nullptr), fail(nullptr), isWord(isWord) {
            for (int i = 0; i < CHARSET_SIZE; i++) c[i] = nullptr;
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
            v = &(*v)->c[(int)*p];
        }
        if (!*v) *v = new Node(true);
        else (*v)->isWord = true;
        return *v;
    }

    void build() {
        std::queue<Node *> q;
        q.push(root);
        root->fail = root;
        root->next = nullptr;
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

    void exec(const char *begin, const char *end) {
        Node *v = root;
        for (const char *p = begin; p != end; p++) {
            while (v != root && !v->c[(int)*p]) v = v->fail;
            v = v->c[(int)*p] ? v->c[(int)*p] : root;
            if (v->isWord) v->apply();
            else if (v->next) v->next->apply();
        }
    }
} t;

int main() {
    int n;
    scanf("%d", &n);
    static char s[MAXN + 1];
    char *p = s;

    static Trie::Node *node[MAXN];
    for (int i = 0; i < n; i++) {
        static char s[MAXN + 1];
        scanf("%s", s);
        int len = strlen(s);
        for (int i = 0; i < len; i++) {
            s[i] -= BASE_CHAR;
            *p = s[i];
            p++;
        }
        *p++ = 0;
        node[i] = t.insert(s, s + len);
    }

    *--p = 0;

    t.build();
    t.exec(s, p);

    for (int i = 0; i < n; i++) {
        printf("%d\n", node[i]->ans);
    }

    return 0;
}