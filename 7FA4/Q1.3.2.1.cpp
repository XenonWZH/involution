// Q1.3.2.1. 最长回文子串
// WzhDnwzWzh

#include <cstdio>

int main()
{
    char str[1001], ans[1001];
    int n = 0, len = 0;

    while (true)
    {
        str[n] = getchar();
        if (str[n] == '\n')
            break;
        for (int begin = 0; begin <= n; begin++)
        {
            for (int i = begin; i <= n; i++)
            {
                if (str[i] != str[n - i + begin])
                    goto endd;
            }
            if (n - begin + 1 > len)
            {
                len = n - begin + 1;
                for (int i = begin; i <= n; i++)
                    ans[i - begin] = str[i];
            }
        endd:;
        }
        n++;
    }

    for (int i = 0; i < len; i++)
        putchar(ans[i]);
    putchar('\n');
    return 0;
}