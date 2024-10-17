#include <bits/stdc++.h>

int main() {
    int n;
    scanf("%d", &n);

    std::vector<int> a;
    while (scanf("%d", &n) != EOF) a.push_back(n);

    std::sort(a.begin(), a.end());

    for (int i = 0; i < a.size() - 1; i++) if (a[i] < a[i + 1] - 1) printf("%d ", a[i] + 1);
    for (int i = 0; i < a.size() - 1; i++) if (a[i] == a[i + 1]) printf("%d\n", a[i]);

    return 0;
}