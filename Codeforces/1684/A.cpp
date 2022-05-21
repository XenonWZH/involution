#include <cstdio>
#include <cstring>
#include <algorithm>

const int MAXN = 9;

int main() {
    int t;

    scanf("%d", &t);

    while (t--) {
        char num[MAXN + 1];
        scanf("%s", num);

        int len = strlen(num);

        if (len == 2) {
            printf("%c\n", num[1]);
            continue;
        }

        char ans = '9';
        for (int i = 0; i < len; i++) ans = std::min(ans, num[i]);

        printf("%c\n", ans);
    }

    return 0;
}