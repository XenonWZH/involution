#include <cstdio>
#include <cstring>

const int MAXN = 200000;

int main() {
    static char s[MAXN + 5], t[MAXN + 5];

    scanf("%s\n%s", s, t);

    int lenS = strlen(s), lenT = strlen(t), posT = 0;

    for (int i = 0; i < lenS; i++, posT++) {
        if (s[i] != t[posT]) {
            puts("No");
            return 0;
        }

        if (s[i] == s[i + 1]) {
            int cntS = 0, cntT = 0;
            for (int j = i; j < lenS && s[j] == s[i]; j++) {
                cntS++;
            }
            for (int j = posT; j < lenT && t[j] == t[posT]; j++) cntT++;
            if (cntT < cntS) {
                puts("No");
                return 0;
            }
            i += cntS - 1, posT += cntT - 1;
        }
    }

    puts(posT == lenT ? "Yes" : "No");

    return 0;
}