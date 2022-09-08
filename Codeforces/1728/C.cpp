#include <cstdio>
#include <queue>
#include <string>

inline int calc(int x) {
    return std::to_string(x).length();
}

int main() {
    int t;
    scanf("%d", &t);

    while (t--) {
        int n;
        scanf("%d", &n);

        std::priority_queue<int> a, b;
        for (int i = 0; i < n; i++) {
            int x;
            scanf("%d", &x);
            a.push(x);
        }
        for (int i = 0; i < n; i++) {
            int x;
            scanf("%d", &x);
            b.push(x);
        }

        int ans = 0;

        while (!a.empty()) {
            int x = a.top();
            int y = b.top();

            if (x > y) {
                a.pop();
                a.push(calc(x));
                ans++;
            } else if (x < y) {
                b.pop();
                b.push(calc(y));
                ans++;
            } else {
                a.pop();
                b.pop();
            }
        }

        printf("%d\n", ans);
    }

    return 0;
}