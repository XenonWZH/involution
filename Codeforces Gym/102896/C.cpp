#include <bits/stdc++.h>

namespace XenonWZH {
const int MAXN = 20;

int n;
std::vector<int> G[MAXN + 1];
std::vector<int> ans;

void dfs(int u) {
    ans.push_back(u);
    
}

int main() {
    scanf("%d", &n);
    for (int i = 2; i <= n; i++) {
        int p;
        scanf("%d", &p);
        G[p].push_back(i);
    }

    dfs(1);

    printf("%zu\n", ans.size());
    for (int e : ans) printf("%d ", e);
    puts("");

    return 0;
}
}

int main() {
    return XenonWZH::main();
}