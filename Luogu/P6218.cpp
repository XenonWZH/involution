#include <cstdio>
#include <vector>

const int MAXN = 31;

int C[MAXN + 1][MAXN + 1];

inline void prepare() {
    for (int i = 0; i <= MAXN; i++) {
        for (int j = 0; j <= i; j++) {
            if (j == 0) C[i][j] = 1;
            else C[i][j] = C[i - 1][j] + C[i- 1][j - 1];
        }
    }
}

int solve(int n) {
    if (n == 0) return 1;

    std::vector<int> nums;
    for (; n; n >>= 1) nums.push_back(n & 1);

    int len = nums.size(), need = (len + 1) / 2;
    int res = 0;
    int last = 0;

    for (int i = len - 1; i >= 0; i--) {
        int x = nums[i];

        if (x) {
            if (i == len - 1) {
                res++;
                for (int j = 1; j <= i; j++) {
                    for (int k = (j + 1) / 2; k <= j - 1; k++) {
                        res += C[j - 1][k];
                    }
                }
            } else {
                for (int j = need - last - 1; j <= i; j++) {
                    res += C[i][j];
                }
            }
        } else last++;

        if (i == 0 && last >= need) res++;
    }

    return res;
}

int main() {
    prepare();

    int l, r;

    scanf("%d %d", &l, &r);

    printf("%d\n", solve(r) - solve(l - 1));

    return 0;
}