#include <bits/stdc++.h>

namespace XenonWZH {
int main() {
    int a, b, c;
    scanf("%d %d %d", &a, &b, &c);

    int ans = 0;
    ans += 2 * a;

    if (c != 0) {
        if (c > 2) {
            ans += 2 * b + 3;
            c -= 2;
            if (c & 1) ans += 3 * (c - 1) / 2;
            else ans += 3 * c / 2;
        } else if (c == 2) {
            ans += 3;
            ans += 2 * b;
        }
    }

    printf("%d\n", ans);

    return 0;
}
}

int main() {
    return XenonWZH::main();
}