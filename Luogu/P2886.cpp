#include <cstdio>
#include <climits>
#include <algorithm>
#include <map>

const int MAXN = 200;

struct Matrix {
    int a[MAXN + 1][MAXN + 1];

    Matrix() { for (int i = 1; i <= MAXN; i++) for (int j = 1; j <= MAXN; j++) a[i][j] = INT_MAX; }

    int &operator()(int i, int j) { return a[i][j]; }
    const int &operator()(int i, int j) const { return a[i][j]; }
};

Matrix operator*(Matrix a, Matrix b) {
    Matrix res;
    for (int i = 1; i <= MAXN; i++) {
        for (int j = 1; j <= MAXN; j++) {
            for (int k = 1; k <= MAXN; k++) {
                if (a(i, k) != INT_MAX && b(k, j) != INT_MAX) {
                    res(i, j) = std::min(res(i, j), a(i, k) + b(k, j));
                }
            }
        }
    }
    return res;
}

Matrix pow(Matrix a, int n) {
    Matrix res = a;
    n--;
    for (; n; n >>= 1, a = a * a) if (n & 1) res = res * a;
    return res;
}

int main() {
    int n, t, s, e;
    scanf("%d %d %d %d", &n, &t, &s, &e);

    Matrix a;
    std::map<int, int> mp;
    int cnt = 0;
    for (int i = 0; i < t; i++) {
        int w, u, v;
        scanf("%d %d %d", &w, &u, &v);
        if (!mp[u]) mp[u] = ++cnt;
        if (!mp[v]) mp[v] = ++cnt;
        a(mp[u], mp[v]) = std::min(a(mp[u], mp[v]), w);
        a(mp[v], mp[u]) = std::min(a(mp[v], mp[u]), w);
    }

    Matrix ans = pow(a, n);
    printf("%d\n", ans(mp[s], mp[e]));

    return 0;
}