// #6. 猜数字 2
// WzhDnwzWzh

#include <vector>
#include "interaction.h"

const int MAXN = 1000000;

int main() {
    int t = get_num();

    static std::vector<int> ans;
    for (int i = 0; i < t; i++) {
        int left = 0, right = MAXN;

        while (left <= right) {
            int mid = (left + right) >> 1;
            int g = guess(i, mid);

            if (g == -1) left = mid + 1;
            else if (g == 1) right = mid - 1;
            else {
                left = mid;
                break;
            }
        }

        ans.push_back(left);
    }

    submit(ans);

    return 0;
}
