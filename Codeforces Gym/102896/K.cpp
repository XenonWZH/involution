#include <bits/stdc++.h>

namespace XenonWZH {
int main() {
    int n;
    scanf("%d", &n);

    int cnt = 1;
    std::map<int, int> vis;
    for (int i = 1; i <= n; i++) {
        int k;
        scanf("%d", &k);

        std::vector<int> p(k + 1);
        bool add = false;

        int mx = 0;
        for (int i = 1; i <= k; i++) {
            scanf("%d", &p[i]);
            mx = std::max(mx, vis[p[i]]);
        }

        mx++;
        cnt = std::max(mx, cnt);

        for (auto e : p) vis[e] = mx;
    }

    printf("%d\n", cnt);

    return 0;
}
}

int main() {
    return XenonWZH::main();
}