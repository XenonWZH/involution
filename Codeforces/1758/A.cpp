#include <bits/stdc++.h>

namespace XenonWZH {
    const int MAXN = 100;

    void solve() {
        static char s[MAXN + 1];
        scanf("%s", s);
        printf("%s", s);
        for (int i = strlen(s) - 1; i >= 0; i--) putchar(s[i]);
        putchar('\n');
    }

    int main() {
        int t;

        scanf("%d", &t);

        while (t--) solve();

        return 0;
    }
}

int main() {
    return XenonWZH::main();
}