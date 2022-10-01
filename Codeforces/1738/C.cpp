#include <cstdio>
#include <iostream>

void solve() {
    int n;
    int cnt0 = 0, cnt1 = 0;

    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        int a;
        scanf("%d", &a);
        if (a % 2)
            cnt1++;
        else
            cnt0++;
        cnt0 &= 1;
    }

    if (cnt0 == 0) {
        if ((cnt1 % 4 == 1 || cnt1 % 4 == 2))
            puts("Bob");
        else
            puts("Alice");
    } else {
        if ((cnt1 % 4 == 1 || cnt1 % 4 == 3 || cnt1 % 4 == 0))
            puts("Alice");
        else
            puts("Bob");
    }
}

int main() {
    int t;

    scanf("%d", &t);

    while (t--) solve();

    return 0;
}