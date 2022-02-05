#include <bits/stdc++.h>

namespace DEBUG {
    void debug_out() { std::cerr << '\n'; }
    template <typename Head, typename... Tail>
    void debug_out(Head H, Tail... T) { std::cerr << ' ' << H, debug_out(T...); }
    #define debug(...) cerr << "[" << #__VA_ARGS__ << "]:", debug_out(__VA_ARGS__)
} using namespace DEBUG;

const int MAXN = 100;

int main() {
    int t;

    scanf("%d", &t);

    while (t--) {
        int n;
        static char str[MAXN + 1];

        scanf("%d%s", &n, &str);

        int cnt0 = 0, cnt1 = 0;
        for (int i = 0; i < n; i++) {
            if (str[i] == '0') cnt0++;
            else cnt1++;
        }

        if (cnt0 >= 2 || cnt1 >= 2) puts("NO");
        else puts("YES");
    }

    return 0;
}