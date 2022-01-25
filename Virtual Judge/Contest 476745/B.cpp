#include <cstdio>
#include <vector>
#include <algorithm>

int main() {
    int n, m;

    scanf("%d%d", &n, &m);

    static std::vector<int> nWay, mWay;

    while (n > 0) {
        nWay.push_back(n);
        if (n % 2 == 0) n /= 2;
        else n = (n - 1) / 2;
    }
    while (m > 0) {
        mWay.push_back(m);
        if (m % 2 == 0) m /= 2;
        else m = (m - 1) / 2;
    }

    int ans;
    for (int lenN = nWay.size(), lenM = mWay.size(), i = 1; lenN - i >= 0 && lenM - i >= 0; i++)
        if (nWay[lenN - i] == mWay[lenM - i])
            ans = nWay[lenN - i];

    printf("%d\n", ans);

    return 0;
}