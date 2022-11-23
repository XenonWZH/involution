#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#include <new>

const int MAXL = 510000;
const int CHARSET_SIZE = 'z' - 'a' + 1;
const int BASE_WORD = 'a';

struct Node {
    Node *ch[CHARSET_SIZE];
    std::vector<Node *> chWord;
    int size, wordID;
    bool isWord;

    Node() : ch(), size(0), isWord(false) {}
} _pool[MAXL + 1], *_curr = _pool, *rt = new (_curr++) Node;

inline void insert(char *begin, char *end) {
    Node *v = rt;
    for (char *p = begin; p != end; p++) {
        v->size++;
        if (!v->ch[*p - BASE_WORD]) v->ch[*p - BASE_WORD] = new (_curr++) Node;
        v = v->ch[*p - BASE_WORD];
    }
    v->size++;
    v->isWord = true;
}

long long ans;

inline bool comp(Node *a, Node *b) {
    int x = a ? a->size : 0;
    int y = b ? b->size : 0;
    return x < y;
}

inline void dfs1(Node *u, Node *last) {
    if (u->isWord) last->chWord.push_back(u);

    for (int i = 0; i < CHARSET_SIZE; i++) {
        if (u->ch[i]) {
            dfs1(u->ch[i], u->isWord ? u : last);
        }
    }
}

inline void dfs2(Node *u, int dfnFa) {
    static int ts = 0;
    int dfn = ts++;

    ans += dfn - dfnFa;

    std::sort(u->chWord.begin(), u->chWord.end(), comp);
    for (int i = 0; i < u->chWord.size(); i++) dfs2(u->chWord[i], dfn);
}

int main() {
    int n;
    scanf("%d", &n);
    while (n--) {
        static char s[MAXL + 1];
        scanf("%s", s);
        int len = strlen(s);

        std::reverse(s, s + len);
        insert(s, s + len);
    }

    dfs1(rt, rt);
    dfs2(rt, 0);

    printf("%lld\n", ans);

    return 0;
}