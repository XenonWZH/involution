// P1079 [NOIP2012 提高组] Vigenère 密码
// WzhDnwzWzh

#include <cstdio>
#include <cctype>
#include <cstring>

int main() {
    char m[1001], c[1001], k[101];
    memset(m, 0, sizeof(m));
    memset(c, 0, sizeof(c));
    memset(k, 0, sizeof(k));

    scanf("%s%s", c, m);

    int mLen = strlen(m), cLen = strlen(c);
    for (int i = 0, pos = 0; i < mLen; i++, pos = (pos + 1) % cLen) {
        k[i] = ((m[i] - 'a' >= 0) ? 'a' : 'A') + (((m[i] - 'a' >= 0) ? (26 + (m[i] - 'a') - (tolower(c[pos]) - 'a')) : (26 + (m[i] - 'A') - (tolower(c[pos]) - 'a'))) % 26);
    }
    k[mLen] = '\0';

    printf("%s\n", k);
    return 0;
}