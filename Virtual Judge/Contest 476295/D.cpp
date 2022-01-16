// D - 分数线划定
// XenonWZH

#include <iostream>
#include <algorithm>

const int MAXN = 5000;

struct Student {
    int k, s;
} st[MAXN + 1];

bool comp(Student a, Student b) {
    if (a.s != b.s) return a.s > b.s;
    return a.k < b.k;
}

int main() {
    int n, m;

    std::cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        std::cin >> st[i].k >> st[i].s;
    }

    std::sort(st + 1, st + n + 1, comp);

    int pos = m * 1.5;
    if (pos > n) pos = n;
    while (pos <= n && st[pos + 1].s == st[pos].s) pos++;

    std::cout << st[pos].s << " " << pos << std::endl;
    for (int i = 1; i <= pos; i++) {
        std::cout << st[i].k << " " << st[i].s << std::endl;
    }

    return 0;
}