#include <cstdio>
#include <algorithm>

const int MAXN = 200000;

#define a(x, y) (a[(x) * m + (y)])

int main() {
    int t;

    scanf("%d", &t);

    while (t--) {
        int n, m;
        static long long a[MAXN];

        scanf("%d %d", &n, &m);
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                scanf("%lld", &a(i, j));
            }
        }

        int pos1 = -1, pos2 = -1;
        for (int i = 0; i < n && pos1 == -1; i++) {
            static int line[MAXN];
            for (int j = 0; j < m; j++) line[j] = a(i, j);
            std::sort(line, line + m);
            for (int j = 0; j < m; j++) {
                if (a(i, j) != line[j]) {
                    if (pos1 == -1) pos1 = j;
                    else if (pos2 == -1) pos2 = j;
                    else {
                        puts("-1");
                        goto endd;
                    }
                }
            }
        }

        if (pos1 == -1) {
            puts("1 1");
            goto endd;
        }
        if (pos2 == -1) pos2 = 0;

        for (int i = 0; i < n; i++) std::swap(a(i, pos1), a(i, pos2));

        for (int i = 0; i < n; i++) {
            for (int j = 1; j < m; j++) {
                if (a(i, j) < a(i, j - 1)) {
                    puts("-1");
                    goto endd;
                }
            }
        }

        printf("%d %d\n", pos1 + 1, pos2 + 1);
    endd:;
    }

    return 0;
}