#include <cstdio>
#include <cstring>
#include <iostream>

const int MAXN = 5e5;
const int LOG_MAXK = 62;

int main() {
    int n;
    unsigned long long k;
    static char s[MAXN + 1];

    scanf("%d %llu", &n, &k);
    scanf("%s", s);

    static char ans[MAXN + 1];
    for (int i = LOG_MAXK; i >= 0 && k > 0; i--) {
        if ((k >> i) & 1) {
            int len = (1llu << i) % n;
            for (int j = 0; j < n; j++) ans[j] = '0' + (s[(j - len + n) % n] ^ s[(j + len) % n]);

            memcpy(s, ans, sizeof(ans));
            k -= (1llu << i);
        }
    }

    printf("%s\n", ans);
    return 0;
}
