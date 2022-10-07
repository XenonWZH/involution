// UVA1585 得分 Score
// WzhDnwzWzh

#include <cstdio>
#include <cstring>

int main()
{
    int n, ans, plus;
    char strs[1000];

    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        scanf("%s", strs);

        ans = plus = 0;
        for (int j = 0; j < strlen(strs); j++)
        {
            if (strs[j] == 'O')
                ans += ++plus;
            else
                plus = 0;
        }

        printf("%d\n", ans);
    }
    return 0;
}