#include <cstdio>
#include <algorithm>

const int MAXN = 1e5;

int main() {
    int t;

    scanf("%d", &t);

    while (t--) {
        int n, q;
        static int a[MAXN + 1], pos[MAXN + 1];

        scanf("%d %d", &n, &q);
        for (int i = 1; i <= n; i++) {
            scanf("%d", &a[i]);
            pos[a[i]] = i;
        }

        int maxp = n;
        static int maxPos[MAXN + 1];
        for (int i = n; i >= 1; i--) {
            maxp = std::min(maxp, pos[i]);
            maxPos[i] = maxp;
        }

        while (q--) {
            int i, k;
            scanf("%d %d", &i, &k);

            if (pos[n] == i) {
                if (pos[n] == 1 || pos[n] == 2) printf("%d\n", k);
                else printf("%d\n", std::max(0, k - i + 2));
            } else {
                if (i == 1 || i == 2) {
                    if (maxPos[a[i]] < i) puts("0");
                    else {
                        if (i == 1) printf("%d\n", std::min(k, std::max(0, maxPos[a[i] + 1] - maxPos[a[i]] - 1)));
                        else printf("%d\n", std::min(k, std::max(0, maxPos[a[i] + 1] - maxPos[a[i]])));
                    }
                } else {
                    if (maxPos[a[i]] < i) puts("0");
                    else printf("%d\n", std::min(std::max(0, k - maxPos[a[i]] + 2), std::max(0, maxPos[a[i] + 1] - maxPos[a[i]])));
                }
            }
        }
    }

    return 0;
}