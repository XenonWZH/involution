#include <bits/stdc++.h>

namespace XenonWZH {

int main() {
    int n;
    scanf("%d", &n);

    std::map<double, int> mp;
    int cnt = 0;
    for (int i = 1; i <= n; i++) {
        double x;
        scanf("%lfL", &x);
        if (!mp[x]) mp[x] = ++cnt;

        int y = mp[x];
        char ch[10];
        int cntt = 0;
        while (y) {
            ch[cntt++] = 'a' + y % 10;
            y /= 10;
        }
        ch[cntt] = '\0';
        printf("%s\n", ch);
    }

    return 0;
}
}

int main() {
    return XenonWZH::main();
}