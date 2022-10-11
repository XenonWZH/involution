#include <bits/stdc++.h>

void solve() {
    std::string a, b;

    std::cin >> a >> b;

    int x;
    if (a == "M") x = 0;
    else if (a.back() == 'S') x = -a.length();
    else x = a.length();
    int y;
    if (b == "M") y = 0;
    else if (b.back() == 'S') y = -b.length();
    else y = b.length();

    if (a == b) puts("=");
    else if (x < y) puts("<");
    else puts(">");
}

int main() {
    int t;

    scanf("%d", &t);

    while (t--) solve();

    return 0;
}