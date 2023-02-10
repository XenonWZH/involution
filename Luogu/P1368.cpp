#include <cstdio>
#include <algorithm>

const int MAXN = 6e5;

int main() {
    int n;
    scanf("%d", &n);

    static int a[MAXN + 1];
    for (int i = 1; i <= n; i++) {
        scanf("%d", &a[i]);
        a[i + n] = a[i];
    }

    int i = 1, j = 2, k;
    while (i <= n && j <= n) {
        for (k = 0; k < n && a[i + k] == a[j + k]; k++) continue;
        if (k == n) break;
        if (a[i + k] > a[j + k]) {
            i = i + k + 1;
            if (i == j) i++;
        } else {
            j = j + k + 1;
            if (i == j) j++;
        }
    }
    int ans = std::min(i, j);

    for (int i = ans; i <= ans + n - 1; i++) printf("%d ", a[i]);
    puts("");

    return 0;
}