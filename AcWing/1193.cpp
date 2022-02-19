#include <cstdio>
#include <cstring>
#include <iostream>
#include <vector>
#include <map>

const int MAXN = 100;

int n;
std::vector<int> e[MAXN + 1], eRev[MAXN + 1];
int fa[MAXN + 1][MAXN + 1], cnt[MAXN + 1][MAXN + 1];
bool vis[MAXN + 1];

void dfsFa(int pos, int dep, int fath) {
    for (int ed : e[pos]) {
        if (cnt[ed][fath] < dep + 1) {
            cnt[ed][fath] = dep + 1;
            fa[ed][fath] = pos;
            dfsFa(ed, dep + 1, fath);
        }
    }
}

void dfsAns(int pos) {
    for (int i = 1; i <= n; i++) {
        if (fa[pos][i] != 0 && !vis[fa[pos][i]]) {
            dfsAns(fa[pos][i]);
        }
    }
    printf("%d ", pos);
    vis[pos] = true;
}

int main() {
    std::cin >> n;
    for (int i = 1; i <= n; i++) {
        int son;
        while (scanf("%d", &son) != EOF) {
            if (son == 0) break;
            e[i].push_back(son);
            eRev[son].push_back(i);
        }
    }

    memset(fa, 0, sizeof(fa));
    memset(cnt, 0, sizeof(cnt));
    for (int i = 1; i <= n; i++) {
        if (eRev[i].empty()) {
            dfsFa(i, 0, i);
        }
    }

    memset(vis, false, sizeof(vis));
    for (int i = 1; i <= n; i++) {
        if (e[i].empty()) {
            dfsAns(i);
        }
    }

    std::cout << std::endl;

    return 0;
}