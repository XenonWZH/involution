// Q1.3.3.1. 小数加减乘除
// WzhDnwzWzh

#include <cstdio>
#include <cmath>

int main()
{
    auto a = 0.0, b = 0.0;
    int lena = 0, lenb = 0;
    char c;

    while (true)
    {
        c = getchar();
        if (c == '.')
            break;
        a = a * 10 + c - '0';
    }
    while (true)
    {
        c = getchar();
        if (c == ' ')
            break;
        a = a * 10 + c - '0';
        lena++;
    }
    a /= pow(10.0, lena);
    while (true)
    {
        c = getchar();
        if (c == '.')
            break;
        b = b * 10 + c - '0';
    }
    while (true)
    {
        c = getchar();
        if (c == '\n')
            break;
        b = b * 10 + c - '0';
        lenb++;
    }
    b /= pow(10.0, lenb);

    printf("%.4f\n%.4f\n%.4f\n", a + b, a - b, a * b);
    if (b == 0)
        printf("div0.\n");
    else
        printf("%.4f\n", a / b);
    return 0;
}