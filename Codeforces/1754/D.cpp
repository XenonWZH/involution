#include <bits/stdc++.h>

int main() {
    int n, x;
    scanf("%d %d", &n, &x);

    std::vector<int> cnt(x + 1);
    for (int i = 0; i < n; i++) {
        int a;
        scanf("%d", &a);
        cnt[a]++;
    }

    for (int i = 1; i < x; i++) {
        if (cnt[i] % (i + 1) != 0) {
            puts("No");
            return 0;
        } else cnt[i + 1] += cnt[i] / (i + 1);
    }

    puts("Yes");

    return 0;
}