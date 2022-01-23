#include <cstdio>
#include <cstring>

const int MAXN = 50;

int main() {
    int t;

    scanf("%d", &t);

    while (t--) {
        static char str[MAXN + 1];
        static int num[MAXN];
        bool ok = true;

        scanf("%s", str);

        int cnt = 0;
        for (int i = 0, n = strlen(str); i < n; i++)
            if (str[i] == 'N')
                cnt++;

        printf("%s\n", cnt == 1 ? "NO" : "YES");
    }

    return 0;
}