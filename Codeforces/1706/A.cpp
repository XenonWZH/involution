#include <cstdio>

const int MAXN = 50;

int main() {
    int t;

    scanf("%d", &t);

    while (t--) {
        int n, m;

        scanf("%d %d", &n, &m);

        static char str[MAXN + 1];
        for (int i = 1; i <= m; i++) str[i] = 'B';
        str[m + 1] = '\0';

        while (n--) {
            int a;
            scanf("%d", &a);

            if (a <= m + 1 - a) {
                if (str[a] == 'B') str[a] = 'A';
                else str[m + 1 - a] = 'A';
            } else {
                if (str[m + 1 - a] == 'B') str[m + 1 - a] = 'A';
                else str[a] = 'A';
            }
        }

        printf("%s\n", str + 1);
    }

    return 0;
}