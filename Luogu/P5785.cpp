#include <cstdio>
#include <vector>

int main() {
    int n, s;
    scanf("%d", &n);
    scanf("%d", &s);

    std::vector<long long> st(n + 1, 0), sc(n + 1, 0);
    for (int i = 1; i <= n; i++) {
        int t, c;
        scanf("%d %d", &t, &c);
        st[i] = st[i - 1] + t, sc[i] = sc[i - 1] + c;
    }

    int l = 1, r = 1;
    std::vector<long long> f(n + 1);
    std::vector<int> q(n + 1);
    q[1] = 0;

    auto binary_search = [&](int i, int k) {
        if (l == r) return q[l];
        int tmpL = l, tmpR = r;
        while (tmpL < tmpR) {
            int mid = tmpL + (tmpR - tmpL) / 2;
            if (f[q[mid + 1]] - f[q[mid]] <= k * (sc[q[mid + 1]] - sc[q[mid]])) tmpL = mid + 1;
            else tmpR = mid;
        }
        return q[tmpL];
    };

    for (int i = 1; i <= n; i++) {
        int p = binary_search(i, s + st[i]);
        f[i] = f[p] - (s + st[i]) * sc[p] + st[i] * sc[i] + s * sc[n];
        while (l < r && (f[q[r]] - f[q[r - 1]]) * (sc[i] - sc[q[r]]) >= (f[i] - f[q[r]]) * (sc[q[r]] - sc[q[r - 1]])) r--;
        q[++r] = i;
    }

    printf("%lld\n", f[n]);

    return 0;
}