#include <cstdio>
#include <random>
#include <vector>
#include <unordered_map>

const int MAXL = 1e7;

int main() {
    int n;

    scanf("%d", &n);

    std::mt19937 rng(std::random_device{}());
    auto rand = [&]() -> unsigned long long { return (1ull << (rng() % 31)) ^ rng(); };

    std::vector<unsigned long long> hash(MAXL + 1);
    for (int i = 0; i <= MAXL; i++) hash[i] = rand();
    std::vector<unsigned long long> list(6);
    for (int i = 0; i < 6; i++) list[i] = rand();

    std::unordered_map<unsigned long long, bool> vis;
    for (int i = 0; i < n; i++) {
        std::vector<int> a(12);
        for (int i = 0; i < 6; i++) {
            scanf("%d", &a[i]);
            a[i + 6] = a[i];
        }

        for (int j = 0; j < 6; j++) {
            unsigned long long res = 0;
            for (int k = 0; k < 6; k++) res += hash[a[j + k]] * list[k];
            if (vis[res]) {
                puts("Twin snowflakes found.");
                return 0;
            } else if (j == 0) vis[res] = true;
        }
        for (int j = 0; j < 6; j++) {
            unsigned long long res = 0;
            for (int k = 0; k < 6; k++) res += hash[a[j + 5 - k]] * list[k];
            if (vis[res]) {
                puts("Twin snowflakes found.");
                return 0;
            } else if (j == 0) vis[res] = true;
        }
    }

    puts("No two snowflakes are alike.");

    return 0;
}