#include <cstdio>
#include <cstring>

const int MAXN = 5e4;
const int MAXA = 1e6;

struct BinaryIndexedTree {
    int a[2 * MAXN + 1], n;

    void init(const int n) {
        this->n = n;
    }

    static int lowbit(const int x) {
        return x & -x;
    }

    void update(const int pos, const int delta) {
        for (int i = pos; i <= n; i += lowbit(i)) a[i] += delta;
    }

    int query(const int pos) {
        int ans = 0;
        for (int i = pos; i > 0; i -= lowbit(i)) ans += a[i];
        return ans;
    }
} bit;

int main() {
    int n;

    scanf("%d", &n);
    bit.init(2 * n);

    int sizeAns = 0;
    static int visited[2 * MAXN + 1];
    static int ans[MAXA + 1];
    memset(visited, 0, sizeof(visited));

    for (int i = 1; i <= 2 * n; i++) {
        int a;
        scanf("%d", &a);

        if (visited[a]) {
            for (int j = bit.query(visited[a]); j < bit.query(i); j++) {
                ans[sizeAns++] = j;
            }
            bit.update(visited[a], -1);
        } else {
            visited[a] = i;
            bit.update(i, 1);
        }
    }

    printf("%d\n", sizeAns);
    for (int i = 0; i < sizeAns; i++) {
        printf("%d\n", ans[i]);
    }

    return 0;
}