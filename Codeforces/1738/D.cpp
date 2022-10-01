#include <cstdio>
#include <iostream>
#include <vector>

const int MAXN = 1e5;

struct Node {
    int size, p;
    Node(int p) : p(p) {}
};

int n;
std::pair<int, std::vector<int>> e[MAXN + 2];

int dfs1(int p) {
    e[p].first = 1;
    if (e[p].second.size() == 0) return 1;
    for (int each : e[p].second) e[p].first += dfs1(each);
    return e[p].first;
}

void dfs2(int p) {
    if (p != 0 && p != n + 1) printf("%d ", p);
    int max = 0;
    for (int each : e[p].second) max = std::max(max, e[each].first);
    for (int each : e[p].second) {
        if (e[each].first != max) {
            dfs2(each);
        }
    }
    for (int each : e[p].second) {
        if (e[each].first == max) {
            dfs2(each);
        }
    }
}

void solve() {
    static int b[MAXN + 1];

    scanf("%d", &n);

    int k = 0;
    bool flag = true;
    for (int i = 1; i <= n; i++) {
        scanf("%d", &b[i]);
        if (b[i] > i) k = i;
        if (b[i] == 0) flag = false;
    }
    printf("%d\n", k);

    for (int i = 0; i <= n + 1; i++) e[i].second.clear();
    for (int i = 1; i <= n; i++) e[b[i]].second.push_back(i);

    if (flag) {
        dfs1(n + 1);
        dfs2(n + 1);
    } else {
        dfs1(0);
        dfs2(0);
    }
    putchar('\n');
}

int main() {
    int t;

    scanf("%d", &t);

    while (t--) solve();

    return 0;
}