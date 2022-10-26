#include <cstdio>
#include <cstring>
#include <vector>

const int CHARSET_SIZE = 'z' - 'a' + 1;
const int BASE_CHAR = 'a';

struct Node {
    Node *ch[CHARSET_SIZE];
    int size;
    bool isWord;

    Node() : ch(), size(0), isWord(false) {}

    inline void insert(char *begin, char *end) {
        Node *v = this;
        for (char *p = begin; p != end; p++) {
            v->size++;
            if (!v->ch[*p - BASE_CHAR]) {
                v->ch[*p - BASE_CHAR] = new Node;
            }
            v = v->ch[*p - BASE_CHAR];
        }
        v->size++;
        v->isWord = true;
    }

    inline bool search(char *begin, char *end) {
        Node *v = this;
        for (char *p = begin; p != end; p++) {
            if (!v->ch[*p - BASE_CHAR]) return false;
            v = v->ch[*p - BASE_CHAR];
        }
        return v->isWord;
    }
};

int main() {
    int n;
    scanf("%d", &n);

    std::vector<Node> nodes(n);
    for (int i = 0; i < n; i++) {
        int l;
        scanf("%d", &l);
        while (l--) {
            char str[21];
            scanf("%s", str);
            nodes[i].insert(str, str + strlen(str));
        }
    }

    int m;
    scanf("%d", &m);
    while (m--) {
        char str[21];
        scanf("%s", str);

        for (int i = 0; i < n; i++) {
            if (nodes[i].search(str, str + strlen(str))) {
                printf("%d ", i + 1);
            }
        }
        putchar('\n');
    }

    return 0;
}