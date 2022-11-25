#include <cstdio>
#include <algorithm>

const int MAXN = 30000;

struct UnionFindSet {
    int head[MAXN], tail[MAXN], prefix[MAXN];

    void init(int n) {
        for (int i = 0; i < n; i++) {
            head[i] = i;
            tail[i] = i;
        }
    }

    int findHead(int x) {
        if (head[x] == x) {
            return x;
        } else {
            if (head[head[x]] != head[x]) {
                prefix[x] += pre(head[x]);
            }
            head[x] = findHead(head[x]);
        }

        return head[x];
    }

    int findTail(int x) {
        return tail[x] == x ? x : tail[x] = findTail(tail[x]);
    }

    int pre(int x) {
        if (head[x] == x) {
            return prefix[x] = 0;
        } else {
            if (head[head[x]] != head[x]) {
                prefix[x] += pre(head[x]);
            }
            head[x] = findHead(head[x]);
        }

        return prefix[x];
    }

    int sum(int x, int y) {
        return std::max(pre(x), pre(y)) - std::min(pre(x), pre(y)) - 1;
    }

    void merge(int x, int y) {
        int head_x = findHead(x);
        int tail_y = findTail(y);
        head[head_x] = tail_y;
        tail[tail_y] = head_x;
        prefix[head_x] = 1;
    }
} ufs;

int main() {
    int m;
    scanf("%d", &m);

    ufs.init(MAXN);
    for (int i = 0; i < m; i++) {
        char command = ' ';
        int x, y;

        while (command != 'M' && command != 'C') command = getchar();
        scanf("%d %d", &x, &y);
        x--, y--;

        if (command == 'M') {
            ufs.merge(x, y);
        } else {
            if (ufs.findHead(x) == ufs.findHead(y)) {
                printf("%u\n", ufs.sum(x, y));
            } else {
                puts("-1");
            }
        }
    }

    return 0;
}