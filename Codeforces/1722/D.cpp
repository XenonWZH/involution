#include <cstdio>
#include <iostream>
#include <algorithm>

const int MAXN = 2e5;

int main() {
    int t;

    scanf("%d", &t);

    while (t--) {
        int n;
        static char s[MAXN + 1];

        scanf("%d", &n);
        scanf("%s", s);

        static long long val[MAXN + 1];
        for (int i = 0; i < n; i++) {
            if (s[i] == 'L') val[i] = i;
            if (s[i] == 'R') val[i] = n - i - 1;
        }

        std::sort(val, val + n);
        long long ans = 0;
        for (int i = 0; i < n; i++) ans += val[i];

        for (int i = 0; i < n; i++) {
            if (n - 1 - val[i] > val[i]) {
                ans -= val[i];
                ans += n - val[i] - 1;
            }
            printf("%lld ", ans);
        }
        putchar('\n');
    }

    return 0;
}