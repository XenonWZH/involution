#include <cstdio>
#include <cstring>
#include <iostream>

const int MAXN = 50;

int main() {
    int t;

    scanf("%d", &t);

    while (t--) {
        int n;
        static char s[MAXN + 4];
        memset(s, 0, sizeof(s));

        scanf("%d", &n);
        scanf("%s", s + 1);

        std::string ans;
        for (int i = 1; i <= n; i++) {
            if (s[i + 2] == '0' && s[i + 3] != '0') {
                ans += 10 * (s[i] - '0') + s[i + 1] - '0' - 1 + 'a';
                i += 2;
            } else ans += s[i] - '0' + - 1 + 'a';
        }

        std::cout << ans << std::endl;
    }

    return 0;
}