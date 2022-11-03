#include <iostream>
#include <string>
#include <vector>
// #include <array>

const int MAXN = 1000000;
const int P = 13331;

int main() {
    std::ios::sync_with_stdio(false);
    // std::cin.tie(nullptr);
    // std::cout.tie(nullptr);
    std::cin.tie(NULL);
    std::cout.tie(NULL);

    int counts = 0;

    // std::array<unsigned long long, MAXN + 1> p;
    static unsigned long long p[MAXN + 1];
    p[0] = 1;
    for (int i = 1; i < MAXN; i++) p[i] = p[i - 1] * P;

    std::string s;
    while (std::cin >> s && s != "END") {
        ++counts;
        int ans = 0, len = s.size();
        s = ' ' + s;

        std::vector<unsigned long long> f1(len + 1), f2(len + 1);
        f2[len + 1] = 0;
        for (int i = 1; i <= len; i++) f1[i] = f1[i - 1] * P + s[i];
        for (int i = len; i >= 1; i--) f2[i] = f2[i + 1] * P + s[i];

        // auto hash1 = [&](int i, int j) { return f1[j] - f1[i - 1] * p[j - i + 1]; };
        // auto hash2 = [&](int i, int j) { return f2[i] - f2[j + 1] * p[j - i + 1]; };
        #define hash1(i, j) (f1[(j)] - f1[(i) - 1] * p[(j) - (i) + 1])
        #define hash2(i, j) (f2[(i)] - f2[(j) + 1] * p[(j) - (i) + 1])

        for (int i = 1; i <= len; i++) {
            int l = 0, r = std::min(i - 1, len - i);
            while (l < r) {
                int mid = (l + r + 1) >> 1;
                if (hash1(i - mid, i - 1) == hash2(i + 1, i + mid)) l = mid;
                else r = mid - 1;
            }
            ans = std::max(l * 2 + 1, ans);
            l = 0, r = std::min(i - 1, len - i + 1);
            while (l < r) {
                int mid = (l + r + 1) >> 1;
                if (hash1(i - mid, i - 1) == hash2(i, i + mid - 1)) l = mid;
                else r = mid - 1;
            }
            ans = std::max(l * 2, ans);
        }

        std::cout << "Case " << counts << ": " << ans << "\n";
    }

    return 0;
}