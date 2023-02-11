#include <cstdio>
#include <bitset>

const int MAXN = 1e3;
const int MAXM = 2e3;

int main() {
    int n, m;
    scanf("%d %d", &n, &m);

    static char s[MAXN + 2];
    static std::bitset<MAXN + 1> a[MAXM + 2];
    for (int i = 1; i <= m; i++) {
        int in;
        scanf("%s %d", s + 1, &in);
        a[i][n + 1] = in;
        for (int j = 1; j <= n; j++) a[i][j] = s[j] - '0';
    }

    int max = n;
    for (int i = 1; i <= n; i++) {
        max = std::max(max, i);
        if (!a[i][i]) {
            for (int j = i + 1; j <= m; j++) {
                if (a[j][i]) {
                    std::swap(a[i], a[j]);
                    max = std::max(max, j);
                    break;
                }
            }
        }
        if (a[i][i] == 0) {
            puts("Cannot Determine");
            return 0;
        }
        for (int k = m; k > i; k--) {
            if (a[k][i]) {
                a[k] ^= a[i];
            }
        }
    }

    for (int i = n; i; i--) {
        for (int j = i - 1; j; j--) {
            if (a[j][i]) {
                a[j] ^= a[i];
            }
        }
    }

    printf("%d\n", max);
    for (int i = 1; i <= n; i++) {
        if (a[i][n + 1]) puts("?y7M#");
        else puts("Earth");
    }

    return 0;
}