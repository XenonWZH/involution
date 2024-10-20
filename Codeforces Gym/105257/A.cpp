#include <cstdio>

int main() {
    int n;
    scanf("%d", &n);

    while (n--) {
        char s[4];
        scanf("%s", s);
        for (int i = 0; i < 3; i++) {
            int x = s[i] - '0';
            printf("%c", ((x >> 2) & 1) ? 'r' : '-');
            printf("%c", ((x >> 1) & 1) ? 'w' : '-');
            printf("%c", ((x >> 0) & 1) ? 'x' : '-');
        }
        puts("");
    }
    return 0;
}