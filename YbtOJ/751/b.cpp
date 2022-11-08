#include <bits/stdc++.h>

namespace XenonWZH {
    int cnt;
    std::vector<std::pair<int, int>> edges;

    void solve(int k, int pos) {
        if (k == 1) return;
        for (int i = 2; i * i <= k; i++) {
            while (k % i == 0) {
                edges.push_back(std::make_pair(pos, cnt + 1));
                solve(i - 1, ++cnt);
                k /= i;
            }
        }
        if (k > 1) {
            edges.push_back(std::make_pair(pos, cnt + 1));
            solve(k - 1, ++cnt);
        }
    }

    int main() {
        freopen("b.in", "r", stdin);
        freopen("b.out", "w", stdout);

        int k;

        while (scanf("%d", &k) != EOF) {
            cnt = 1;
            edges.clear();
            solve(k, 1);

            printf("%d\n", cnt);
            for (auto e : edges) printf("%d %d\n", e.first, e.second);
        }

        fclose(stdin);
        fclose(stdout);

        return 0;
    }
}

int main() {
    return XenonWZH::main();
}