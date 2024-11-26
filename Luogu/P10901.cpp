#include <bits/stdc++.h>

int main() {
    int n;
    scanf("%d", &n);

    std::vector<int> a(n);
    for (int i = 0; i < n; i++) scanf("%d", &a[i]);

    std::sort(a.begin(), a.end(), [](int x, int y) {
        const int circ[10] = { 1, 0, 0, 0, 1, 0, 1, 0, 2, 1 };
        int xx = x, yy = y, cntx = 0, cnty = 0;
        while (xx > 0) cntx += circ[xx % 10], xx /= 10;
        while (yy > 0) cnty += circ[yy % 10], yy /= 10;
        if (cntx == cnty) return x < y;
        else return cntx < cnty;
    });

    for (int i = 0; i < n; i++) printf("%d ", a[i]);
    puts("");

    return 0;
}