#include <cstdio>

const int MAXN = 3000;

int trie[MAXN * MAXN + 2][2], tot = 1;
int end[MAXN * MAXN + 2];

inline void insert(char *str, int len) {
    int p = 1;
    for (int i = 0; i < len; i++) {
        int ch = str[i] - '0';
        if (trie[p][ch] == 0) trie[p][ch] = ++tot;
        p = trie[p][ch];
        end[p]++;
    }
}

void dfs(int p) {
    if (end[p] > 1) printf("%d\n", end[p]);
    if (trie[p][0]) dfs(trie[p][0]);
    if (trie[p][1]) dfs(trie[p][1]);
}

int main() {
    int n;
    static char str[MAXN + 1];

    scanf("%d", &n);
    scanf("%s", str);

    for (int i = 0; i < n; i++) {
        insert(str + i, n - i);
    }

    dfs(1);

    return 0;
}