// 10082 - WERTYU
// WzhDnwzWzh

#include <cstdio>

const char dict[] = "`1234567890-=QWERTYUIOP[]\\ASDFGHJKL;'ZXCVBNM,./";

int main()
{
    int c, i;

    while ((c = getchar()) != EOF)
    {
        for (i = 0; dict[i] != '\0' && dict[i] != c ; i++);
        if (dict[i] == c)
            putchar(dict[i - 1]);
        else
            putchar(c);
    }

    return 0;
}