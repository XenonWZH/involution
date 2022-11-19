#include <cstdio>
#include <vector>
#include <algorithm>

struct BinaryIndexedTree {
    int n;
    std::vector<int> a;

    void init(int n) {
        this->n = n;
        a.resize(n + 1);
        std::fill(a.begin(), a.end(), 0);
    }

    static int lowbit(int x) {
        return x & -x;
    }

    void update(int pos, int delta) {
        for (; pos <= n; pos += lowbit(pos)) {
            a[pos] += delta;
        }
    }

    int query(int pos) {
        int res = 0;
        for (; pos; pos -= lowbit(pos)) res += a[pos];
        return res;
    }
} bit;

void solve() {
    int n;
    scanf("%d", &n);

    std::vector<std::pair<int, int>> a[2];
    for (int i = 0; i < 2; i++) a[i].resize(n);
    for (int i = 0; i < n; i++) {
        scanf("%d %d", &a[0][i].first, &a[0][i].second);
        a[1][i] = std::make_pair(a[0][i].second, a[0][i].first);
    }
    std::sort(a[0].begin(), a[0].end());
    std::sort(a[1].begin(), a[1].end());

    for (int i = 0; i < 2; i++) {
        bit.init(n);
        for (int j = 0; j < n; j++) bit.update(a[i][j].first, 1);
        for (int j = 1; j <= n; j++) {
            if (bit.query(j) == n / 2) {
                puts("2");
                return;
            } else if (bit.query(j) > n / 2) break;
        }
    }

    for (int i = 0; i < 2; i++) {
        bit.init(n);
        for (int j = 0; j < n; j++) {
            bit.update(a[i][j].second, 1);
            if (j == n - 1 || a[i][j + 1].first != a[i][j].first) {
                int l = 0, r = n;
                while (l < r) {
                    int mid = l + (r - l + 1) / 2;
                    if (bit.query(mid) <= j + 1 - n / 2) l = mid;
                    else r = mid - 1;
                }
                if (bit.query(l) == j + 1 - n / 2) {
                    puts("3");
                    return;
                }
            }
        }
    }

    puts("4");
}

int main() {
    int t;

    scanf("%d", &t);

    while (t--) solve();

    return 0;
}