#include <cstdio>
#include <cstring>
#include <cmath>

const int MAXN = 2e5;

int main() {
    int t;

    scanf("%d", &t);

    while (t--) {
        static char str[MAXN + 1];

        scanf("%s", str);

        int len = strlen(str);
        int bracket = 0, question = 0;

        for (int i = 0; i < len; i++) {
            if (str[i] == '(') bracket++;
            else if (str[i] == ')') bracket--;
            else question++;

            if (bracket + question == 1) {
                bracket = 1;
                question = 0;
            }
        }

        if (abs(bracket) == question) puts("YES");
        else puts("NO");
    }

    return 0;
}