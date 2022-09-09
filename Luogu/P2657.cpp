#include <cmath>
#include <cstdio>
#include <vector>

const int MAXN = 11;

long long f[MAXN][MAXN];

void init() {
    for (int i = 0; i <= 9; i++) f[1][i] = 1;

    for (int i = 2; i < MAXN; i++) {
        for (int j = 0; j <= 9; j++) {
            for (int k = 0; k <= 9; k++) {
                if (std::abs(j - k) >= 2) {
                    f[i][j] += f[i - 1][k];
                }
            }
        }
    }
}

int dp(int n) {
    if (n == 0) return 0;

    std::vector<int> nums;
    while (n) {
        nums.push_back(n % 10);
        n /= 10;
    }

    int res = 0;
    int last = -2;
    for (int i = nums.size() - 1; i >= 0; i--) {
        int x = nums[i];
        for (int j = i == nums.size() - 1; j < x; j++)
            if (std::abs(j - last) >= 2) res += f[i + 1][j];

        if (std::abs(x - last) >= 2) last = x;
        else break;

        if (!i) res++;
    }

    for (int i = 1; i < nums.size(); i++) {
        for (int j = 1; j <= 9; j++) {
            res += f[i][j];
        }
    }

    return res;
}

int main() {
    init();

    int a, b;

    scanf("%d %d", &a, &b);

    printf("%d\n", dp(b) - dp(a - 1));

    return 0;
}