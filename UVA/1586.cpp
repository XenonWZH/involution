// UVA1586 分子量 Molar mass
// WzhDnwzWzh

#include <cstdio>
#include <cstring>
#include <cmath>

int main()
{
    double ans, atom;
    int n, num;
    char strs[1000];

    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        scanf("%s", strs);

        ans = atom = 0, num = -1;
        for (int j = 0; j < strlen(strs); j++)
        {
            if (strs[j] >= '0' && strs[j] <= '9')
            {
                if (num == -1)
                    num = strs[j] - '0';
                else
                    num = num * 10 + strs[j] - '0';
            }
            else
            {
                ans += atom * abs(num);
                switch (strs[j])
                {
                case 'C':
                    atom = 12.01;
                    break;
                case 'H':
                    atom = 1.008;
                    break;
                case 'O':
                    atom = 16.00;
                    break;
                case 'N':
                    atom = 14.01;
                    break;
                default:
                    break;
                }
                num = -1;
            }
        }
        ans += atom * abs(num);

        printf("%.3f\n", ans);
    }
    return 0;
}