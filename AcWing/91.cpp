// 91. 最短Hamilton路径
// WzhDnwzWzh

#include <iostream>
#include <cstring>

int f[1 << 20][20];

int hamilton(int n, int weight[20][20]) {
    memset(f, 0x3f, sizeof(f));
    f[1][0] = 0;
    for (int i = 1; i < 1 << n; i++) {
        for (int j = 0; j < n; j++) {
            if (i >> j & 1 == 1) {
                for (int k = 0; k < n; k++) {
                    if ((i ^ 1 << j) >> k & 1 == 1) {
                        f[i][j] = std::min(f[i][j], f[i ^ 1 << j][k] + weight[k][j]);
                    }
                }
            }
        }
    }
    return f[(1 << n) - 1][n - 1];
}

int main() {
    int n, weight[20][20];
    std::cin >> n;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            std::cin >> weight[i][j];
        }
    }
    std::cout << hamilton(n, weight) << std::endl;
    return 0;
}