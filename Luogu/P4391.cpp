#include <cstdio>
#include <vector>

const int MAXN = 1e6;

int main() {
    int n;
    scanf("%d", &n);

    static char s[MAXN + 2];
    scanf("%s", s + 1);

    std::vector<int> next(n + 1, 0);
    for (int i = 2, j = 0; i <= n; i++) {
        while (j && s[i] != s[j + 1]) j = next[j];
        if (s[i] == s[j + 1]) j++;
        next[i] = j;
    }

    printf("%d\n", n - next[n]);

    return 0;
}