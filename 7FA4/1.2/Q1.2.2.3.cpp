// Q1.2.2.3. 灯的开关
// WzhDnwzWzh

#include <iostream>
#include <cstring>

const int MAXN = 10000;

int main() {
    int n, m, op;
    static int d[MAXN + 1];
    memset(d, 0, sizeof(0));

    std::cin >> n >> m;
    while (m > 0) {
        std::cin >> op;

        for (int i = 1; op * i <= n; i++) d[op * i] = d[op * i] == 1 ? 0 : 1;
        m--;
    }


    for (int i = 1; i <= n; i++) std::cout << d[i] << " ";
    std::cout << std::endl;
    return 0;
}