#include <cstdio>
#include <cstring>
#include <algorithm>

const int MAXN = 20;

inline unsigned long long pow(int a, int b) {
    unsigned long long ans = 1;
    for (int i = 0; i < b; i++) ans *= a;
    return ans;
}

int main() {
    int t;

    scanf("%d", &t);

    while (t--) {
        char n[MAXN + 2];
        unsigned long long num;

        scanf("%s", n);
        sscanf(n, "%llu", &num);

        int len = strlen(n);
        int ll = len;

        unsigned long long ans = 0;
        for (int i = 1; i < len; i++) {
            if (len % i != 0) continue;

            unsigned long long tmp = 0;
            for (int j = 0; j < i; j++) tmp = tmp * 10 + n[j] - '0';

            unsigned long long tmp1 = 0;
            for (int j = 0; j < len / i; j++) tmp1 = tmp1 * pow(10, i) + tmp;

            if (tmp1 > num) {
                if (tmp != pow(10, i - 1)) {
                    tmp1 = 0;
                    for (int j = 0; j < len / i; j++) tmp1 = tmp1 * pow(10, i) + tmp - 1;
                    ans = std::max(ans, tmp1);
                }
            } else ans = std::max(ans, tmp1);
        }
        if (ans == 0) ans = pow(10, ll - 1) - 1;

        printf("%llu\n", ans);
    }

    return 0;
}