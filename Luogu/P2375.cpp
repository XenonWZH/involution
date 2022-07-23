#include <cstdio>
#include <cstring>

const int MAXN = 1000000;
const long long MOD = 1000000007;

int nxt[MAXN + 1], num[MAXN + 1];
int realNum[MAXN + 1];

inline long long kmp(char *str) {
    int len = strlen(str);
    nxt[0] = nxt[1] = num[0] = num[1] = 0;

    for (int i = 2, j = 0, k = 0; i <= len; i++) {
        while (j > 0 && str[i - 1] != str[j]) j = nxt[j];
        while ((k > 0 && str[i - 1] != str[k]) || k >= i / 2) k = nxt[k];

        if (str[i - 1] == str[k]) {
            k++;
            realNum[i] = num[k] + 1;
        } else realNum[i] = 0;

        if (str[j] == str[i - 1]) nxt[i] = ++j, num[i] = num[j] + 1;
        else nxt[i] = num[i] = 0;
    }

    long long ans = 1;
    for (int i = 1; i <= len; i++) ans = (ans * (realNum[i] + 1)) % MOD;
    return ans;
}

int main() {
    int t;

    scanf("%d", &t);

    while (t--) {
        static char str[MAXN + 1];

        scanf("%s", str);

        printf("%lld\n", kmp(str));
    }

    return 0;
}
