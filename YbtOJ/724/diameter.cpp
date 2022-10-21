#include <cstdio>
#include <vector>

int main() {
    freopen("diameter.in", "r", stdin);
    freopen("diameter.out", "w", stdout);

    int n, k;

    scanf("%d %d", &n, &k);

    if (k == 2) {
        for (int i = 1; i <= n - 1; i++) printf("%d %d\n", i, i + 1);
        return 0;
    }

    std::vector<std::vector<int>> p(k, {1});
    for (int i = k + 2; i <= n; i++) p[i % k].push_back(i);
    for (int i = 0; i < k; i++) p[i].push_back(i + 2);

    for (auto i : p) {
        int size = i.size();
        for (int j = 0; j < size - 1; j++) printf("%d %d\n", i[j], i[j + 1]);
    }

    fclose(stdin);
    fclose(stdout);

    return 0;
}