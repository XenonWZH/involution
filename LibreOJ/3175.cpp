#include <cstdio>
#include <cstring>
#include <vector>

const int MAXN = 2e5;

struct BinaryIndexedTree {
    int a[MAXN + 1], n;

    void init(const int n) { this->n = n; }

    static int lowbit(const int x) { return x & -x; }

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
    static int a[2 * MAXN + 1];

    scanf("%d", &n);
    n *= 2;

    static std::vector<int> pos[2 * MAXN + 1];
    bit.init(n);

    for (int i = 1; i <= n; i++) {
        scanf("%d", &a[i]);
        bit.update(i, 1);
        pos[a[i] + n].push_back(i);
    }

    static bool visited[2 * MAXN + 1];
    long long ans = 0;
    memset(visited, false, sizeof(visited));

    for (int i = n; i >= 1; i--) {
        if (visited[i]) continue;
        visited[i] = true;
        pos[a[i] + n].pop_back();

        int x = pos[n - a[i]].back();
        pos[n - a[i]].pop_back();
        ans += bit.query(i - 1) - bit.query(x);
        bit.update(x, -1);

        visited[x] = true;
        if (a[i] < 0) ans++;
    }

    printf("%lld\n", ans);

    return 0;
}
