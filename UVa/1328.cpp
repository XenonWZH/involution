#include <cstdio>
#include <string>
#include <vector>

const int MAXN = 1000000;

int main() {
    int n, counts = 0;

    while (scanf("%d", &n) != EOF && n) {
        printf("Test case #%d\n", ++counts);

        static char s[MAXN + 2];
        scanf("%s", s + 1);

        std::vector<int> next(n + 1);
        next[1] = 0;
        for (int i = 2, j = 0; i <= n; i++) {
            while (j && s[i] != s[j + 1]) j = next[j];
            if (s[i] == s[j + 1]) j++;
            next[i] = j;

            if (next[i] != 0 && i % (i - next[i]) == 0) printf("%d %d\n", i, i / (i - next[i]));
        }

        putchar('\n');
    }

    return 0;
}