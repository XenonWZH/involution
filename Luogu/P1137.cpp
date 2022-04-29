#include <cstdio>
#include <cstring>
#include <vector>
#include <queue>

const int MAXN = 100000;

int n, m;
std::vector<int> e[MAXN + 1];
int inDeg[MAXN + 1], f[MAXN + 1];

inline void topo() {
    std::queue<int> q;
    for (int i = 1; i <= n; i++) {
        f[i] = 1;
        if (inDeg[i] == 0) {
            q.push(i);
        }
    }

    while (!q.empty()) {
        for (int each : e[q.front()]) {
            if (--inDeg[each] == 0) {
                q.push(each);
                f[each] = std::max(f[each], f[q.front()] + 1);
            }
        }
        q.pop();
    }
}

int main() {
    scanf("%d%d", &n, &m);

    memset(inDeg, 0, sizeof(inDeg));
    for (int i = 1, x, y; i <= m; i++) {
        scanf("%d%d", &x, &y);
        e[x].push_back(y);
        inDeg[y]++;
    }

    topo();

    for (int i = 1; i <= n; i++) printf("%d\n", f[i]);

    return 0;
}