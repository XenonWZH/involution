// A - 快速排序
// XenonWZH

#include <iostream>
#include <algorithm>

const int MAXN = 1e5;

int main() {
    int n;
    static int a[MAXN];

    std::cin >> n;
    for (int i = 0; i < n; i++) {
        std::cin >> a[i];
    }

    std::sort(a, a + n);

    for (int i = 0; i < n; i++) {
        std::cout << a[i] << " ";
    }

    std::cout << std::endl;
    return 0;
}