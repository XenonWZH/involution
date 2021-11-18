// P1095 [NOIP2007 普及组] 守望者的逃离
// WzhDnwzWzh

#include <cstring>
#include <cmath>
#include <iostream>

const int MAXN = 300000 * 4 + 1000;

int main() {
    int m, s, t;

    std::cin >> m >> s >> t;

    int run = 0, tp = 0, time = 0;
    while (time < t) {
        ++time;
        run += 17;
        if (m >= 10) {
            m -= 10;
            tp += 60;
        } else m += 4;
        if (run < tp) run = tp;
        if (run >= s) {
            std::cout << "Yes" << std::endl << time << std::endl;
            return 0;
        }
    }

    std::cout << "No" << std::endl << run << std::endl;

    return 0;
}
