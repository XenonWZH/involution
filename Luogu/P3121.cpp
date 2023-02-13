#include <cstdio>
#include <cstring>
#include <queue>
#include <stack>

const int MAXN = 1e5;

int trie[MAXN + 1][26], tot;
int end[MAXN + 1], fail[MAXN + 1];

void insert(char *s, int id) {
    int len = strlen(s), p = 0;
    for (int i = 0; i < len; i++) {
        if (!trie[p][s[i] - 'a']) trie[p][s[i] - 'a'] = ++tot;
        p = trie[p][s[i] - 'a'];
    }
    end[p] = id;
}

void build() {
    std::queue<int> q;
    for (int i = 0; i < 26; i++) {
        if (trie[0][i]) {
            q.push(trie[0][i]);
        }
    }
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        for (int i = 0; i < 26; i++) {
            if (trie[u][i]) {
                fail[trie[u][i]] = trie[fail[u]][i];
                q.push(trie[u][i]);
            } else trie[u][i] = trie[fail[u]][i];
        }
    }
}

int main() {
    int n;
    static char s[MAXN + 1], t[MAXN + 1];
    static int lt[MAXN + 1];
    scanf("%s", s);
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        scanf("%s", t);
        lt[i] = strlen(t);
        insert(t, i);
    }
    build();

    int len = strlen(s);
    std::stack<int> f;
    std::deque<char> ans;
    f.push(0);
    for (int i = 0; i < len; i++) {
        int u = trie[f.top()][s[i] - 'a'];
        f.push(u);
        ans.push_back(s[i]);
        if (end[f.top()]) {
            int m = lt[end[f.top()]];
            for (int j = 0; j < m; j++) {
                f.pop();
                ans.pop_back();
            }
        }
    }

    while (!ans.empty()) {
        putchar(ans.front());
        ans.pop_front();
    }
    puts("");

    return 0;
}