#include <bits/stdc++.h>

int main() {
    int n;
    scanf("%d", &n);

    std::vector<int> a;
    for (int i = 1; i <= 9; i++) a.push_back(i);

    int ans = 0;
    do {
        for (int i = 1; i < 9; i++) {
            long long x = 0;
            for (int j = 0; j < i; j++) x = x * 10 + a[j];
            for (int j = i + 1; j < 9; j++) {
                long long y = 0;
                for (int k = i; k < j; k++) y = y * 10 + a[k];
                long long z = 0;
                for (int k = j; k < 9; k++) z = z * 10 + a[k];
                if (x != 0 && y != 0 && z != 0 && y % z == 0 && x + y / z == n) ans++;
            }
        }
    } while (std::next_permutation(a.begin(), a.end()));

    printf("%d\n", ans);

    return 0;
}