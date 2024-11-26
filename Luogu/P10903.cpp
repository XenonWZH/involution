#include <cstdio>
#include <vector>

int main() {
    int n, m;
    scanf("%d %d", &n, &m);

    std::vector<int> l(n + 1), r(n + 1);
    for (int i = 1; i <= m; i++) scanf("%d %d", &l[i], &r[i]);

    std::vector<int> a(n + 2);
    for (int i = 1; i <= m; i++) a[l[i]]++, a[r[i] + 1]--;
    for (int i = 1; i <= n; i++) a[i] += a[i - 1];

    std::vector<int> b(n + 2), c(n + 2);
    b[0] = c[0] = 0;
    for (int i = 1; i <= n; i++) b[i] = b[i - 1] + (a[i] == 1);
    for (int i = 1; i <= n; i++) c[i] = c[i - 1] + (a[i] == 0);

    for (int i = 1; i <= m; i++) printf("%d\n", b[r[i]] - b[l[i] - 1] + c[l[i] - 1] + c[n] - c[r[i]]);

    return 0;
}