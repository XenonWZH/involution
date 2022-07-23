#include <cstdio>
#include <cstring>

const int MAXN = 500000;

int trie[MAXN + 2][2], tot = 1;
int end[MAXN + 2];
int size[MAXN + 2];

inline void insert(int *str, int len) {
    int p = 1;
    for (int i = 0; i < len; i++) {
        int ch = str[i];
        if (trie[p][ch] == 0) trie[p][ch] = ++tot;
        p = trie[p][ch];
    }
    end[p]++;
}

int getSize(int p) {
    if (size[p] != -1) return size[p];
    if (p == 0) return 0;

    size[p] = end[p];
    size[p] += getSize(trie[p][0]);
    size[p] += getSize(trie[p][1]);

    return size[p];
}

int search(int *str, int len) {
    int p = 1, cnt = 0;

    for (int i = 0; i < len; i++) {
        p = trie[p][str[i]];
        if (p == 0) return cnt;
        cnt += end[p];
    }

    cnt += getSize(trie[p][0]);
    cnt += getSize(trie[p][1]);

    return cnt;
}

int main() {
    int m, n;

    scanf("%d %d", &m, &n);

    for (int i = 0; i < m; i++) {
        int len;
        static int b[MAXN];

        scanf("%d", &len);
        for (int j = 0; j < len; j++) {
            scanf("%d", &b[j]);
        }

        insert(b, len);
    }

    memset(size, -1, sizeof(size));

    for (int i = 0; i < n; i++) {
        int len;
        static int c[MAXN];

        scanf("%d", &len);
        for (int j = 0; j < len; j++) {
            scanf("%d", &c[j]);
        }

        printf("%d\n", search(c, len));
    }

    return 0;
}