#include <cstdio>
#include <cstring>

const int MAXN = 1000000;

int kmp[MAXN + 1];
int lenA, lenB, j;
char a[MAXN + 1], b[MAXN + 1];

int main() {
    scanf("%s%s", a + 1, b + 1);

    lenA = strlen(a + 1);
    lenB = strlen(b + 1);

    for (int i = 2; i <= lenB; i++) {
        while (j && b[i] != b[j + 1]) j = kmp[j];
        if (b[j + 1] == b[i]) j++;
        kmp[i] = j;
    }

    j = 0;
    for (int i = 1; i <= lenA; i++) {
        while (j > 0 && b[j + 1] != a[i]) j = kmp[j];
        if (b[j + 1] == a[i]) j++;
        if (j == lenB) {
            printf("%d\n", i - lenB + 1);
            j = kmp[j];
        }
    }

    for (int i = 1; i <= lenB; i++) {
        printf("%d ", kmp[i]);
    }
    putchar('\n');

    return 0;
}
