#include <bits/stdc++.h>

namespace XenonWZH {
struct BIT {
    std::vector<int> a;
    int n;

    void init(int n) {
        a.resize(n + 1, 0);
        for (int i = 0; i <= n; i++) a[i] = 0;
        this->n = n;
    }

    static int lowbit(const int x) {
        return x & -x;
    }

    void update(int pos, int delta) {
        for (int i = pos; i <= n; i += lowbit(i)) a[i] += delta;
    }

    int query(int pos) {
        int ans = 0;
        for (int i = pos; i > 0; i -= lowbit(i)) ans += a[i];
        return ans;
    }
} bit;

void solve() {
    int n;
    scanf("%d", &n);

    std::vector<std::pair<int, int>> a(n + 1);
    for (int i = 1; i <= n; i++) scanf("%d", &a[i].first);
    for (int i = 1; i <= n; i++) scanf("%d", &a[i].second);
    std::sort(a.begin() + 1, a.end());

    int ans = 0;
    bit.init(n + 1);
    for (int i = 1; i <= n; i++) {
        ans = (ans + bit.query(n) - bit.query(a[i].second)) % 2;
        bit.update(a[i].second, 1);
    }
    printf("%c", ans ? 'A' : 'B');
 
    for (int i = 1; i <= n - 1; i++) {
        char ch[10];
        int l, r, d;
        scanf("%s %d %d %d", ch, &l, &r, &d);
        if (l != r) {
            int len = r - l + 1, lsize = len - d % len, rsize = len - lsize;
            ans = (ans + 1ll * lsize * rsize) % 2;
        }
        printf("%c", ans ? 'A' : 'B');
    }
 
    puts("");
}
 
int main() {
    int t;
    scanf("%d", &t);
 
    while (t--) solve();
 
    return 0;
}
};
 
int main() { return XenonWZH::main(); }