// Q1.3.2.4. 进制转换
// WzhDnwzWzh

#include <cstdio>
#include <cctype>
#include <cmath>

int main()
{
    char source[100], answer[100], ns[100] = {'\0'}, tmp;
    long long num = 0, src, ans, t = 0, cnt;
    
    while (true)
    {
        tmp = getchar();
        if (!isspace(tmp))
        {
            if (tmp >= '0' && tmp <= '9')
                src = tmp - '0' + 1;
            else
                src = tmp - 'A' + 11;
            break;
        }
    }
    while (true)
    {
        tmp = getchar();
        if (!isspace(tmp))
        {
            if (tmp >= '0' && tmp <= '9')
                ans = tmp - '0' + 1;
            else
                ans = tmp - 'A' + 11;
            break;
        }
    }
    while (true)
    {
        tmp = getchar();
        if (tmp == '\n' && ns[0] != '\0')
            break;
        if (!isspace(tmp))
            ns[t++] = tmp;
    }
    for (int i = t - 1; i >= 0; i--)
    {
        if (ns[i] >= '0' && ns[i] <= '9')
            num += (ns[i] - '0') * pow(src, t - 1 - i);
        else
            num += (ns[i] - 'A' + 10) * pow(src, t - 1 - i);
    }
    if (num == 0)
    {
        putchar('0');
        putchar('\n');
        return 0;
    }

    for (t = 1; t <= num; t *= ans);
    t /= ans;
    while (num > 0 || t > 0)
    {
        cnt = 0;
        while (num >= t)
        {
            num -= t;
            cnt++;
        }
        if (cnt <= 9)
            putchar(cnt + '0');
        else
            putchar(cnt - 10 + 'A');
        t /= ans;
    }

    putchar('\n');
    return 0;
}