#include <cstdio>
#include <iostream>
#include <vector>
#include <algorithm>

struct Soldier {
    int b, j;

    bool operator<(const Soldier &other) const {
        return j > other.j;
    }
};

int main() {
    int n, kase = 0;

    while (scanf("%d", &n) != EOF && n != 0) {
        std::vector<Soldier> s(n);
        for (int i = 0; i < n; i++) scanf("%d %d", &s[i].b, &s[i].j);

        std::sort(s.begin(), s.end());
        int ans = 0, time = 0;
        for (int i = 0; i < n; i++) {
            time += s[i].b;
            ans = std::max(ans, time + s[i].j);
        }

        printf("Case %d: %d\n", ++kase, ans);
    }

    return 0;
}