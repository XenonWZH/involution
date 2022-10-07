// 815 - Flooded!
// WzhDnwzWzh

#include <iostream>
#include <cstdio>
#include <algorithm>

const int MAXN = 30;

int main() {
    int n, m, cnt = 0;
    float water, height;
    static int squ[MAXN * MAXN];

    while (std::cin >> n >> m) {
        if (n == 0 && m == 0) break;
        for (int i = 0; i < n * m; i++) {
            std::cin >> squ[i];
        }
        std::cin >> water;
        water /= 100;
        std::sort(squ, squ + n * m);

        int pos = 0;
        while (pos < n * m && squ[pos] == squ[pos + 1]) pos++;
        while (water > pos) {
            for (int i = 0; i <= pos; i++) {
                squ[i]++;
            }
            water -= pos + 1;
            if (water > 0) {
                while (pos < n * m && squ[pos] == squ[pos + 1]) pos++;
            }
        }
        height = squ[pos] + water * 1.0 / (pos + 1);

        std::cout << "Region " << ++cnt << std::endl;
        printf("Water level is %.2f meters.\n", height);
        printf("%.2f percent of the region is under water.\n", (pos + 1) * 100.0 / (m * n));
        std::cout << std::endl;
    }

    return 0;
}