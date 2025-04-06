#include <bits/stdc++.h>

int calc(int x) {
    return x - (x / 2 - x / 4);
}

int main() {
    int l, r;
    scanf("%d %d", &l, &r);
    printf("%d\n", calc(r) - calc(l - 1));
    return 0;
}