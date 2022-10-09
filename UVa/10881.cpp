#include <cstdio>
#include <algorithm>

const int MAXN = 10000;
const char dirName[][10] = { "L", "Turning", "R" };

struct Ant {
    int id, p, d;

    bool operator< (const Ant &a) const {
        return p < a.p;
    }
} before[MAXN + 1], after[MAXN + 1];

int order[MAXN + 1], counts = 0;

void solve() {
    counts++;

    int l, t, n;

    scanf("%d %d %d", &l, &t, &n);

    for (int i = 0, p, d; i < n; i++) {
        char c;
        scanf("%d %c", &p, &c);
        d = (c == 'L' ? -1 : 1);
        before[i] = (Ant){i, p, d}, after[i] = (Ant){0, p + t * d, d};
    }

    printf("Case #%d:\n", counts);
    std::sort(before, before + n);
    for (int i = 0; i < n; i++)
        order[before[i].id] = i;
    std::sort(after, after + n);

    for (int i = 0; i < n - 1; i++) {
        if (after[i].p == after[i + 1].p) {
            after[i].d = after[i + 1].d = 0;
        }
    }
    for (int i = 0; i < n; i++) {
        int a = order[i];
        if (after[a].p < 0 || after[a].p > l) puts("Fell off");
        else printf("%d %s\n", after[a].p, dirName[after[a].d + 1]);
    }
    printf("\n");
}

int main() {
    int t;

    scanf("%d", &t);

    while (t--) solve();

  return 0;
}