// Q1.3.2.3. 汉字排序
// WzhDnwzWzh

#include <cstdio>

struct character
{
    char pron[10] = {'\0'}, num[100] = { '0', '\0' };
    int alpha, noise;

    friend bool operator>(const character a, const character b)
    {
        int i;
        for (i = 0; a.pron[i] != '\0' && b.pron[i] != '\0'; i++)
            if (a.pron[i] != b.pron[i])
                return a.pron[i] > b.pron[i];
        if (a.pron[i] == '\0' && b.pron[i] != '\0')
            return false;
        if (a.pron[i] != '\0' && b.pron[i] == '\0')
            return true;
        if (a.alpha != b.alpha)
            return a.alpha > b.alpha;
        if (a.noise != b.noise)
        {
            if (a.noise == 0 || b.noise == 0)
                return a.noise < b.noise;
            else
                return a.noise > b.noise;
        }
        for (i = 0; a.num[i] != '\0' && b.num[i] != '\0'; i++);
        if (a.num[i] == '\0' && b.num[i] != '\0')
            return false;
        if (a.num[i] != '\0' && b.num[i] == '\0')
            return true;
        for (i = 0; a.num[i] != '\0' && b.num[i] != '\0'; i++)
            if (a.num[i] != b.num[i])
                return a.num[i] > b.num[i];
        return false;
    }
};

int main()
{
    character cha[2000], cht;
    char ct;
    int n = 0, cnt;
    bool flag = true;

    while (true)
    {
        ct = getchar();
        if (ct == '~')
            break;
        cha[n].pron[0] = ct;
        cnt = 1;
        while (true)
        {
            ct = getchar();
            if (ct == ' ')
                break;
            cha[n].pron[cnt++] = ct;
        }
        while (true)
        {
            ct = getchar();
            if (ct == ' ')
                break;
            cha[n].alpha = ct - '0';
        }
        while (true)
        {
            ct = getchar();
            if (ct == ' ')
                break;
            cha[n].noise = ct - '0';
        }
        cnt = 0;
        while (true)
        {
            ct = getchar();
            if (ct == '\n')
                break;
            cha[n].num[cnt++] = ct;
        }
        n++;
    }

    while (flag)
    {
        flag = false;
        for (int i = 0; i < n - 1; i++)
            if (cha[i] > cha[i + 1])
            {
                flag = true;
                cht = cha[i];
                cha[i] = cha[i + 1];
                cha[i + 1] = cht;
            }
    }

    for (int i = 0; i < n; i++)
        printf("%s %d %d %s\n", cha[i].pron, cha[i].alpha, cha[i].noise, cha[i].num);
    return 0;
}