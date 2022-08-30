#include <cstdio>

const int MAXN = 10;

int main() {
    int t;

    scanf("%d", &t);

    while (t--) {
        int n;
        static char str[MAXN + 1];

        scanf("%d", &n);
        scanf("%s", str);

        int T = 0, i = 0, m = 0, u = 0, r = 0;
        bool flag = false;
        for (int e = 0; e < n; e++) {
            if (str[e] == 'T') T++;
            else if (str[e] == 'i') i++;
            else if (str[e] == 'm') m++;
            else if (str[e] == 'u') u++;
            else if (str[e] == 'r') r++;
            else flag = true;
        }

        if (flag || n != 5 || T != 1 || i != 1 || m != 1 || u != 1 || r != 1) puts("NO");
        else puts("YES");
    }

    return 0;
}