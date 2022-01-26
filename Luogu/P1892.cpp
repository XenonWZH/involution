#include <cstdio>
#include <cstring>
#include <vector>

const int MAXN = 1000;

int fa[MAXN + 1];

void makeSet(int size) {
    for (int i = 1; i <= size; i++) fa[i] = i;
}

int find(int x) {
    if (x != fa[x]) return find(fa[x]);
    else return fa[x];
}

void unionSet(int x, int y) {
    x = find(x);
    y = find(y);
    fa[x] = y;
}

int main() {
    int n, m;

    scanf("%d%d", &n, &m);

    makeSet(n);

    static std::vector<int> en[MAXN + 1];

    for (int i = 0; i < m; i++) {
        char str[5];
        int x, y;
        scanf("%s%d%d", str, &x, &y);

        if (str[0] == 'E') {
            en[x].push_back(y);
            en[y].push_back(x);
        } else unionSet(x, y);
    }

    for (int i = 1; i <= n; i++)
        for (int j = 1, len = en[i].size(); j < len; j++)
            unionSet(en[i][j - 1], en[i][j]);

    int ans = 0;
    for (int i = 1; i <= n; i++)
        if (find(i) == i)
            ans++;

    printf("%d\n", ans);

    return 0;
}