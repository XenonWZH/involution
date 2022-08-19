#include <cstdio>
#include <cctype>
#include <algorithm>
 
const int MAXN = 500;
 
int main() {
    int t;
 
    scanf("%d", &t);
 
    while (t--) {
        int n, m;
        static int a[MAXN + 1][MAXN + 1];
 
        scanf("%d %d", &n, &m);

        int ans = 0;
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                char ch = ' ';
                while (!isdigit(ch)) ch = getchar();
                a[i][j] = ch - '0';
                ans += a[i][j];
            }
        }

        int mins = 4;
        for (int i = 1; i <= n - 1; i++) {
            for (int j = 1; j <= m - 1; j++) {
                if (a[i][j] + a[i + 1][j] + a[i][j + 1] + a[i + 1][j + 1] <= 2) mins = 0;
                if (a[i][j] + a[i + 1][j] + a[i][j + 1] + a[i + 1][j + 1] == 3) mins = std::min(mins, 1);
                if (a[i][j] + a[i + 1][j] + a[i][j + 1] + a[i + 1][j + 1] == 4) mins = std::min(mins, 2);
            }
        }


        printf("%d\n", ans - mins);
    }
 
    return 0;
}