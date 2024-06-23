#include <cstdio>
#include <vector>
#include <map>

int main() {
    int t = 0;
    int n;

    while (scanf("%d", &n) != EOF && n) {
        std::vector<int> s(n + 1);
        std::map<int, int> list;
        for (int i = 1; i <= n; i++) {
            scanf("%d", &s[i]);
            list[s[i]]++;
        }

        printf("Game %d:\n", ++t);

        while (true) {
            std::vector<int> in(n + 1);
            std::map<int, int> tmp = list;
            bool con = false;
            for (int i = 1; i <= n; i++) {
                scanf("%d", &in[i]);
                if (in[i]) con = true;
            }
            if (!con) break;

            int a = 0, b = 0;
            for (int i = 1; i <= n; i++) if (in[i] == s[i]) a++, tmp[in[i]]--;
            for (int i = 1; i <= n; i++) if (in[i] != s[i] && tmp[in[i]] > 0) b++, tmp[in[i]]--;

            printf("    (%d,%d)\n", a, b);
        }
    }

    return 0;
}