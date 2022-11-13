#include <cstdio>
#include <vector>

int main() {
    int t;

    scanf("%d", &t);

    while (t--) {
        int n;
        scanf("%d", &n);

        std::vector<int> a(n);
        for (int i = 0; i < n; i++) scanf("%d", &a[i]);

        int ans = 0;
        for (int i = 0; i < n; i++) ans ^= a[i];

        if (ans) puts("Yes");
        else puts("No");
    }

    return 0;
}