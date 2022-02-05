#include <bits/stdc++.h>

inline long long myLog(long long x) {
    long long ans = 0;
    while (1ll << ans <= x) ans++;
    return ans;
}

int main() {
    int t;

    std::cin >> t;

    while (t--) {
        long long a, s;

        std::cin >> a >> s;

        s = s - a - a;
        if (s < 0) {
            std::cout << "No" << std::endl;
            continue;
        } else {
            bool con = true;
            for (long long i = 0, dep = myLog(a); i < dep; i++)
                if ((s & a) >> i & 1) {
                    std::cout << "No" << std::endl;
                    con = false;
                    break;
                }
            if (con) std::cout << "Yes" << std::endl;
        }
    }

    return 0;
}