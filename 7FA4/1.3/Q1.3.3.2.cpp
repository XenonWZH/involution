// Q1.3.3.2. 温度转换
// WzhDnwzWzh

#include <cstdio>
#include <cmath>

int main()
{
    auto a = 0.0;
    char c;
    int lena = 0;
    bool below = false;

    while (true)
    {
        c = getchar();
        if (c == '-')
        {
            below = true;
            continue;
        }
        if (c == '.')
            break;
        if (below)
            a = a * 10 - c + '0';
        else
            a = a * 10 + c - '0';
    }
    while (true)
    {
        c = getchar();
        if (c == '\n')
            break;
        if (below)
            a = a * 10 - c + '0';
        else
            a = a * 10 + c - '0';
        lena++;
    }
    a /= pow(10.0, lena);

    printf("%.4f\n", (a - 32) * 5 / 9);
    return 0;
}