#include <cstdio>

int main() {
    char str[4];

    scanf("%s", str);

    if (str[0] == str[1] && str[1] == str[2]) {
        puts("-1");
        return 0;
    }

    if (str[0] != str[1] && str[0] != str[2]) putchar(str[0]);
    else if (str[0] != str[1] && str[1] != str[2]) putchar(str[1]);
    else if (str[0] != str[2] && str[1] != str[2]) putchar(str[2]);
    putchar('\n');

    return 0;
}